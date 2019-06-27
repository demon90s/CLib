#ifndef MEM_H
#define MEM_H

#include "except/except.h"

extern const Except_T Mem_failed;

extern void* Mem_alloc(long nbytes, const char* file, int line);
extern void* Mem_calloc(long count, long nbytes, const char* file, int line);
extern void Mem_free(void* ptr);
extern void* Mem_resize(void* ptr, long nbytes, const char* file, int line);

#define ALLOC(nbytes) \
    Mem_alloc((nbytes), __FILE__, __LINE__)

#define CALLOC(count, nbytes) \
    Mem_calloc((count), (nbytes), __FILE__, __LINE__)

#define NEW(p) ((p) = ALLOC((long)sizeof *(p)))

#define NEW0(p) ((p) = CALLOC(1, (long)sizeof *(p)))

#define FREE(p) ((void)(Mem_free(p), (p) = 0))

#define RESIZE(p, nbytes) ((p) = Mem_resize((p), (nbytes), __FILE__, __LINE__))

#endif
