#include <assert.h>
#include <stdlib.h>
#include "stack.h"

#define T Stack_T

struct T
{
	int count;
	struct elem
	{
		void *x;
		struct elem *link;
	} *head;
};

T Stack_new(void)
{
	T stk;

	stk = (T) malloc(sizeof(*stk));
	assert(stk);

	stk->count = 0;
	stk->head = NULL;

	return stk;
}

int Stack_empty(T stk)
{
	assert(stk);
	return stk->count == 0;
}

void Stack_push(T stk, void *x)
{
	struct elem *t;

	assert(stk);
	t = (struct elem *) malloc(sizeof(struct elem));
	assert(t);

	t->x = x;
	t->link = stk->head;
	stk->head = t;
	stk->count++;
}

void Stack_pop(T stk)
{
	struct elem *t;

	assert(stk);
	assert(stk->count > 0);

	t = stk->head;
	stk->head = t->link;
	stk->count--;

	free(t->x);
	free(t);
}

void *Stack_top(T stk)
{
	assert(stk && !Stack_empty(stk));
	return stk->head->x;
}

void Stack_free(T * stk)
{
	struct elem *t, *u;

	assert(stk && *stk);
	for (t = (*stk)->head; t; t = u)
	{
		u = t->link;
		free(t->x);
		free(t);
	}
	free(*stk);
}
