#include <stdio.h>
#include <stdlib.h>
#include "unity/unity.h"
#include "test_except.h"
#include "test_array.h"
#include "test_list.h"
#include "test_stack.h"
#include "test_stdinread.h"

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_except);
	/* RUN_TEST(test_array); */
	/* RUN_TEST(test_list); */
	RUN_TEST(test_stack);
	/* RUN_TEST(test_stdinread); */

	return UNITY_END();
}
