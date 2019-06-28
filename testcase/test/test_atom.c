#include <stdlib.h>
#include <stdio.h>
#include "atom/atom.h"

void test_atom(void)
{
	int i;

	for (i = 0; i < 50000; i++) {
		Atom_int(i);
	}

	Atom_destroy();
}
