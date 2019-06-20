#include "array.h"
#include <stdlib.h>
#include <string.h>

typedef struct ArrayElement_ {
    void *value;
} ArrayElement;

typedef struct Array_ {
    int capacity;
    int size;
    ArrayElement *beg;          /* first element of array */
} Array;

Array* array_init(int sz)
{
    if (sz <= 0)
        return NULL;

    Array *arr = (Array*)malloc(sizeof(Array));
    arr->capacity = sz;
    arr->size = 0;
    arr->beg = (ArrayElement*)malloc(sizeof(ArrayElement) * sz);
    memset(arr->beg, 0, sizeof(ArrayElement) * sz);

    return arr;
}

void array_destroy(Array *arr)
{
    int i;

    for (i = 0; i < arr->size; i++) {
        if (arr->beg[i].value != NULL) {
            free(arr->beg[i].value);
        }
    }

    free(arr->beg);
    free(arr);
}

void array_pushback(Array *arr, void* value)
{
    ArrayElement *new_element;

    if (arr->size == arr->capacity) {
        /* resize */
        new_element = (ArrayElement*)malloc(sizeof(ArrayElement) * arr->capacity * 2);
        memset(new_element, 0, sizeof(ArrayElement) * arr->capacity * 2);
        memcpy(new_element, arr->beg, sizeof(ArrayElement) * arr->capacity);

        free(arr->beg);

        arr->beg = new_element;
        arr->capacity *= 2;
    }

    arr->beg[arr->size++].value = value;
}

void* array_getvalue(Array *arr, index_t index)
{
    if (index >= array_size(arr))
        return NULL;

    return arr->beg[index].value;
}

int array_setvalue(Array *arr, index_t index, void *value)
{
    if (index >= array_size(arr))
        return 1;

    ArrayElement *element = &arr->beg[index];
    if (element->value != NULL)
        free(element->value);
    
    element->value = value;

    return 0;
}

int array_size(Array *arr)
{
    return arr->size;
}
