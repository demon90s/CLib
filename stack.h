#ifndef STACK_INCLUDED
#define STACK_INCLUDED

/*
	stack
	- the ADT type is Stack_T
	- capacity no limit
	- store and manage the dynamic value
*/

#define T Stack_T

typedef struct T* T;

/* create a new stack */
extern T Stack_new(void);

/* return 1 if stack is empty, otherwise 0 */
extern int Stack_empty(T stk);

/* push the value x to stack */
extern void Stack_push(T stk, void* x);

/* pop a value from stack */
extern void Stack_pop(T stk);

/* get top value of stack */
extern void* Stack_top(T stk);

/* free the stack */
extern void Stack_free(T* stk);

#undef T

#endif
