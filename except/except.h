#ifndef EXCEPT_H
#define EXCEPT_H

#include <setjmp.h>

/* exception library for C */

/* the ADT type of exception object */
#define T Except_T
typedef struct T {
	const char* reason;
} T;

/* this sturct hold the except status and
   informations of handle functions */
typedef struct Except_Frame Except_Frame;
struct Except_Frame {
	Except_Frame* prev;
	jmp_buf env;
	const char* file;
	int line;
	const T* exception; /* except object, must be a static or global variable */
};

enum { Except_entered = 0,
       Except_raised,
       Except_handled,
       Except_finalized
     };

extern Except_Frame* except_stack;
extern const Except_T Assert_Failed;

void Except_raise(const T* e, const char* file, int line);

#define RAISE(e) Except_raise(&(e), __FILE__, __LINE__)
#define RERAISE Except_raise(frame.exception, frame.file, frame.line)

/* you must pop exception stack on function return */
#define RETURN switch (except_stack = except_stack->prev, 0) default: return

#define TRY do { \
	volatile int flag; \
	Except_Frame frame; \
	frame.prev = except_stack; \
	except_stack = &frame; \
	flag = setjmp(frame.env); \
	if (flag == Except_entered) { \
		/* here is our CODE which may RAISE an exception */

#define EXCEPT(e) \
		if (flag == Except_entered) /* if our CODE has no exception raised, pop stack  */ \
			except_stack = except_stack->prev; \
	} \
	else if (frame.exception == &(e)) { /* match the exception, do handler code */ \
		flag = Except_handled; \
		/* here is our HANDLE CODE */

#define ELSE \
		if (flag == Except_entered) \
			except_stack = except_stack->prev; \
	} \
	else { \
		flag = Except_handled; \
		/* here is our HANDLE CODE */

#define FINALLY \
		if (flag == Except_entered) \
			except_stack = except_stack->prev; \
	} \
	{ /* finally we are here */ \
		if (flag == Except_entered) \
			flag = Except_finalized; \
		/* here is our CLEAR CODE */

#define END_TRY \
		if (flag == Except_entered) \
			except_stack = except_stack->prev; \
	} \
	if (flag == Except_raised) RERAISE; /* if uncaught, reraise it */ \
} while(0)

#undef T

#endif /* EXCEPT_H */
