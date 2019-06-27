#include "except/except.h"
#include "except/assert.h"
#include "unity/unity.h"

Except_T foo_exception = { "!!Foo Exception!!" };

void test_except(void)
{
	int handled = 0;
	int finally = 0;

	/* RAISE(foo_exception); */

	TRY {
		/* if you want to return in try block, use this Macro */
		/* RETURN; */

		RAISE(foo_exception);
		TEST_ASSERT(0); /* never reach here */
	}
	EXCEPT(foo_exception) {
		handled = 1;
	}
	ELSE {
		handled = 0;
	}
	FINALLY {
		finally = 1; /* always reach here */
		/* RERAISE; */
	}
	END_TRY;

	TEST_ASSERT(handled);
	TEST_ASSERT(finally);
}

void test_assert(void)
{
	int catched = 0;

	TRY {
		assert(0);
	}
	ELSE {
		catched = 1;

		/* a friendly notice */
		/*
		fprintf(stderr, "An internal error has occurred, please blablabla...\n");
		RERAISE;
		*/
	}
	END_TRY;

	TEST_ASSERT(catched);
}
