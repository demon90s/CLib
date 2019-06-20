#ifndef ARRAY_H
#define ARRAY_H

/* dynamic array */

typedef struct Array_ Array;

typedef unsigned int index_t;

/* create an dynamic array with size sz */
Array* array_init(int sz);

/* destroy the array, free all element */
void array_destroy(Array *arr);

/* pushback a new element with value to array */
void array_pushback(Array *arr, void* value);

/* get array's value by index, NULL if invalid */
void* array_getvalue(Array *arr, index_t index);

/* set array's value by index, return 0 if succ, else false */
int array_setvalue(Array *arr, index_t index, void *value);

/* get array size */
int array_size(Array *arr);

#endif /* ARRAY_H */
