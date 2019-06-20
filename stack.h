#ifndef STACK_H
#define STACK_H 

typedef struct Stack_ Stack;

/* create a new stack with max_size sz */
Stack* stack_init(int sz);

/* destroy the stack, and free all value */
void stack_destroy(Stack *s);

/* return the top element value, NULL if stack is empty */
void* stack_top(Stack *s);

/* push one element to stack */
void stack_push(Stack *s, void* value);

/* pop one element from stack */
void stack_pop(Stack *s);

/* return the size of stack */
int stack_size(Stack *s);

#endif /* STACK_H */
