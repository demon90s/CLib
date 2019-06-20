#include "stack.h"
#include <stdlib.h>
#include <string.h>

typedef struct StackElement_ {
    void* value;    /* dynamic object allocate by user */
} StackElement;

typedef struct Stack_ {
    int max_size;
    int size;           /* this is top index */
    StackElement* beg;  /* point to first element */
} Stack;

Stack* stack_init(int sz)
{
    if (sz <= 0)
        return NULL;

    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->max_size = sz;
    s->size = 0;
    s->beg = (StackElement*)malloc(sizeof(StackElement*) * sz);
    memset(s->beg, 0, sizeof(StackElement*) * sz);

    return s;
}

void stack_destroy(Stack* s)
{
    while (stack_size(s) > 0) {
        stack_pop(s);
    }

    free(s->beg);

    free(s);
}

void* stack_top(Stack *s)
{
    if (stack_size(s) <= 0)
        return NULL;

    return s->beg[s->size - 1].value;
}

void stack_push(Stack *s, void* value)
{
    StackElement *beg;

    if (stack_size(s) == s->max_size) {
        /* realloc */
        beg = (StackElement*)malloc(sizeof(StackElement) * s->max_size * 2);
        memset(beg, 0, sizeof(StackElement) * s->max_size * 2);
        memcpy(beg, s->beg, sizeof(StackElement) * s->max_size);

        free(s->beg);

        s->max_size = s->max_size * 2;
        s->beg = beg;
    }

    s->beg[s->size++].value = value;
}

void stack_pop(Stack *s)
{
    void *value = stack_top(s);

    if (value != NULL) {
        free(value);
        s->size--;
    }
}

int stack_size(Stack *s)
{
    return s->size;
}
