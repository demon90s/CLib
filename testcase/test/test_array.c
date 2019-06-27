#include "container/array.h"
#include "unity/unity.h"
#include <stdio.h>
#include <stdlib.h>

void test_array()
{
	int i;
	Array* arr;

	arr = array_init(1);

	for (i = 0; i < 10; i++) {
		int* value = (int*) malloc(sizeof(int));
		*value = i;
		array_pushback(arr, value);
	}

	{
		int* value = (int*) malloc(sizeof(int));
		*value = 999;
		array_setvalue(arr, 0, value);

		TEST_ASSERT_EQUAL(999, *(int*)array_getvalue(arr, 0));
	}

	for (i = 1; i < array_size(arr); i++) {
		TEST_ASSERT_EQUAL(i, *(int*) array_getvalue(arr, i));
	}

	array_destroy(arr);
}
