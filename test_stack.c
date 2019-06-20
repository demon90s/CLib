#include "test_stack.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void test_stack()
{
    int i;
    Stack *s;
    int *value;

    s = stack_init(1);

    for (i = 0; i < 10; i++)
    {
        value = (int*)malloc(sizeof(int));
        *value = i;
        stack_push(s, value);
    }

    while (stack_size(s) > 0) {
        printf("%d\n", *(int*)stack_top(s));

        stack_pop(s);
    }

    stack_destroy(s);
}
