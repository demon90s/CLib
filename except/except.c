#include <stdlib.h>
#include <stdio.h>
#include "except.h"

#define T Except_T

Except_Frame* except_stack = NULL;

void Except_raise(const T* e, const char* file, int line)
{
	Except_Frame* p = except_stack;
	if (p == NULL) {
		fprintf(stderr, "Uncaught exception");
		if (e->reason)
			fprintf(stderr, " %s", e->reason);
		else
			fprintf(stderr, " at 0x%p", e);
		if (file && line > 0)
			fprintf(stderr, " raised at %s:%d\n", file, line);
		fprintf(stderr, "Abort\n");
		fflush(stderr);
		abort();
	}

	p->exception = e;
	p->file = file;
	p->line = line;

	/* pop except */
	except_stack = except_stack->prev;

	/* give to handle functions */
	longjmp(p->env, Except_raised);
}
