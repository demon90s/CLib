#include "test_array.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>

void test_array()
{
    int i;
    Array *arr;

    arr = array_init(1);

    for (i = 0; i < 10; i++) {
        int *value = (int*)malloc(sizeof(int));
        *value = i;
        array_pushback(arr, value);
    }

    {
        int *value = (int*)malloc(sizeof(int));
        *value = 999;
        array_setvalue(arr, 0, value);
    }

    printf("array: ");
    for (i = 0; i < array_size(arr); i++) {
        printf(" %d", *(int*)array_getvalue(arr, i));
    }
    printf("\n");

    array_destroy(arr);
}
