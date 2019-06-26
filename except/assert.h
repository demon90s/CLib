#undef assert
#ifndef ASSERT_H
#define ASSERT_H

#ifdef NDEBUG
#define assert(e) ((void)0)
#else
#include "except.h"
extern void assert(int e);
extern const Except_T Assert_failed;
#define assert(e) ((void)((e) || (RAISE(Assert_failed), 0)))
#endif

#endif
