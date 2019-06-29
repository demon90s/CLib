#include <stdio.h>
#include <stdlib.h>
#include "unity/unity.h"

extern void test_except(void);
extern void test_assert(void);
extern void test_mem(void);
extern void test_atom(void);
extern void test_array(void);
extern void test_list(void);
extern void test_stack(void);
extern void test_stdinread(void);

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_atom);
	RUN_TEST(test_list);
	/*
	RUN_TEST(test_except);
	RUN_TEST(test_assert);
	RUN_TEST(test_mem);
	RUN_TEST(test_array);
	RUN_TEST(test_stack);

	RUN_TEST(test_stdinread);
	*/

	return UNITY_END();
}
