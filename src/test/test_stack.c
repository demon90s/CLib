#include <stdio.h>
#include <stdlib.h>
#include "unity/unity.h"
#include "test_stack.h"
#include "container/stack.h"

void test_stack()
{
	int i;
	Stack_T s;
	int* value;

	s = Stack_new();

	for (i = 0; i < 10; i++) {
		value = (int*) malloc(sizeof(int));
		*value = i;
		Stack_push(s, value);
	}

	i = 9;
	while (!Stack_empty(s)) {
		/* printf("%d\n", *(int *) Stack_top(s)); */
		TEST_ASSERT((*(int*) Stack_top(s)) == i--);

		Stack_pop(s);
	}

	Stack_free(&s);
}
