#include <stdlib.h>
#include <string.h>
#include "except/assert.h"
#include "arena.h"

#define T Arena_T
#define THRESHOLD 10 /* max free nodes on freechunks */

const Except_T Arena_new_failed = {"Arena creation failed"};
const Except_T Arena_failed = {"Arena allocation failed"};

union align {
	int i;
	long l;
	long* lp;
	void* p;
	void (*fp)(void);
	float f;
	double d;
	long double ld;
};

struct T {
	T prev;			/* beginning of previous big block */
	char* avail;	/* beginning of first free block */
	char* limit;	/* end of the big block */
};

union header {
	struct T b;
	union align a;
};

static T freechunks;
static int nfree;

T Arena_new(void)
{
	T arena = malloc(sizeof(*arena));
	if (arena == NULL)
		RAISE(Arena_new_failed);
	arena->prev = NULL;
	arena->limit = arena->avail = NULL;
	return arena;
}

void Arena_dispose(T* ap)
{
	assert(ap && *ap);
	Arena_free(*ap);
	free(*ap);
	*ap = NULL;
}

void* Arena_alloc(T arena, long nbytes, const char* file, int line)
{
	assert(arena);
	assert(nbytes > 0);

	/* round nbytes up to an alignment boundary */
	nbytes = ((nbytes + sizeof(union align) - 1) /
	          (sizeof(union align))) * (sizeof(union align));

	while (nbytes > arena->limit - arena->avail) {
		/* get a new chunk */
		T ptr;
		char* limit;

		/* ptr <- a new chunk */
		if ((ptr = freechunks) != NULL) {
			freechunks = freechunks->prev;
			nfree--;
			limit = ptr->limit;
		}
		else {
			long m = sizeof(union header) + nbytes + 10 * 1024;
			ptr = malloc(m);
			if (ptr == NULL) {
				/* raise Arena_failed */
				if (file == NULL)
					RAISE(Arena_failed);
				else
					Except_raise(&Arena_failed, file, line);
			}
			limit = (char*)ptr + m;
		}

		*ptr = *arena;
		arena->avail = (char*)((union header*)ptr + 1);
		arena->limit = limit;
		arena->prev = ptr;
	}

	arena->avail += nbytes;
	return arena->avail - nbytes;
}

void* Arena_calloc(T arena, long count, long nbytes, const char* file, int line)
{
	void* ptr;
	assert(count > 0);
	ptr = Arena_alloc(arena, count * nbytes, file, line);
	memset(ptr, '\0', count * nbytes);
	return ptr;
}

void Arena_free(T arena)
{
	assert(arena);
	while (arena->prev) {
		struct T tmp = *arena->prev;
		/* free the chunk described by arena */
		if (nfree < THRESHOLD) {
			arena->prev->prev = freechunks;
			freechunks = arena->prev;
			nfree++;
			freechunks->limit = arena->limit;
		}
		else {
			free(arena->prev);
		}

		*arena = tmp;
	}

	assert(arena->limit == NULL);
	assert(arena->avail == NULL);
}
