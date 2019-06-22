#include "test_stack.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void test_stack()
{
	int i;
	Stack_T s;
	int *value;

	s = Stack_new();

	for (i = 0; i < 10; i++)
	{
		value = (int *) malloc(sizeof(int));
		*value = i;
		Stack_push(s, value);
	}

	while (!Stack_empty(s))
	{
		printf("%d\n", *(int *) Stack_top(s));

		Stack_pop(s);
	}

	Stack_free(&s);
}
