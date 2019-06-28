#include "mem/mem.h"
#include "unity/unity.h"

void test_mem(void)
{
	char* p;

	p = ALLOC(1000);
	TEST_ASSERT(p);
	FREE(p);
	TEST_ASSERT(p == NULL);

	p = CALLOC(1, sizeof(char));
	TEST_ASSERT(*p == 0);
	FREE(p);
	TEST_ASSERT(p == NULL);

	NEW(p);
	TEST_ASSERT(p);
	FREE(p);
	TEST_ASSERT(p == NULL);

	NEW0(p);
	TEST_ASSERT(*p == 0);
	FREE(p);
	TEST_ASSERT(p == NULL);

	NEW(p);
	TEST_ASSERT(p);
	*p = 100;
	RESIZE(p, 10);
	TEST_ASSERT(p);
	TEST_ASSERT(*p == 100);
	FREE(p);
	TEST_ASSERT(p == NULL);

	/* exception test */
	{
		int catched = 0;
		TRY {
			unsigned long nbytes = 2;
			while (1)
			{
				p = ALLOC(nbytes);
				FREE(p);
				nbytes *= 2;
			}
		}
		EXCEPT (Mem_failed) {
			catched = 1;
		}
		ELSE {
			/* Assertion failed */
		}
		END_TRY;

		TEST_ASSERT(catched);
	}
}
