#include "assert.h"

const Except_T Assert_failed = {"Assert failed"};

void (assert)(int e)
{
	assert(e);
}