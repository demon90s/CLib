#include "test_except.h"
#include "except/except.h"
#include "unity/unity.h"

Except_T foo_exception = { "!!Foo Exception!!" };

void test_except()
{
	int handled = 0;
	int finally = 0;

	/* RAISE(foo_exception); */

	TRY {
		RAISE(foo_exception);
		TEST_ASSERT(0); /* never do this */
	}
	EXCEPT(foo_exception) {
		handled = 1;
	}
	ELSE {
		handled = 0;
	}
	FINALLY {
		finally = 1; /* always do this */
		/* RERAISE; */
	}
	END_TRY;

	TEST_ASSERT(handled);
	TEST_ASSERT(finally);
}
