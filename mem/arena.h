#ifndef ARENA_H
#define ARENA_H

#include "except/except.h"

/*
	memory pool
	the ADT type is Arena_T
*/

#define T Arena_T

typedef struct T* T;

extern const Except_T Arena_new_failed;
extern const Except_T Arena_failed;

/*
	create a new memery pool, return it pointer
	if can not create, it raise Arena_new_failed exception
*/
extern T Arena_new(void);

/*
	release the memory pool, and it's all blocks
*/
extern void Arena_dispose(T* ap);

/*
	allocate a uninitialized block from memory pool
	block size is nbytes
	if can not allocate, it raise Arena_failed exception
*/
extern void* Arena_alloc(T arena, long nbytes, const char* file, int line);

/*
	allocate a block from memory pool, initialized with 0
	block size is count * nbytes
	if can not allocate, it raise Arena_failed exception
*/
extern void* Arena_calloc(T arena, long count, long nbytes, const char* file, int line);

/*
	release the blocks of memory pool
*/
extern void Arena_free(T arena);

#endif
