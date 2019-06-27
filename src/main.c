#include <stdio.h>
#include <stdlib.h>
#include "unity/unity.h"
#include "test/test_except.h"
#include "test/test_array.h"
#include "test/test_list.h"
#include "test/test_stack.h"
#include "test/test_stdinread.h"

int main()
{
	UNITY_BEGIN();

	RUN_TEST(test_except);
	RUN_TEST(test_assert);
	/* RUN_TEST(test_array); */
	/* RUN_TEST(test_list); */
	RUN_TEST(test_stack);
	/* RUN_TEST(test_stdinread); */

	return UNITY_END();
}
