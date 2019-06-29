#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "unity/unity.h"
#include "mem/mem.h"
#include "container/list.h"

struct Foo {
	int a;
};

void free_foo(void** foo, void* cl)
{
	struct Foo** p;
	p = (struct Foo**)foo;
	FREE(*p);
}

void test_list()
{
	List_T list;

	list = List_list(NULL);
	TEST_ASSERT(list == NULL);

	list = List_list((void*)"N1", (void*)"N2", (void*)"N3", NULL);
	TEST_ASSERT(list);
	List_free(&list);
	TEST_ASSERT(list == NULL);

	struct Foo f1 = {1}, f2 = {2}, f3 = {3};
	list = List_push(NULL, (void*)&f1);
	list = List_push(list, (void*)&f2);
	list = List_push(list, (void*)&f3);
	TEST_ASSERT(List_length(list) == 3);

	struct Foo* f;
	list = List_pop(list, (void**)&f);
	TEST_ASSERT(f->a == 3);
	TEST_ASSERT(List_length(list) == 2);

	struct Foo f4 = {4}, f5 = {5};
	{
		List_T list2;
		list2 = List_list((void*)&f4, (void*)&f5, NULL);
		list = List_append(list, list2);
		TEST_ASSERT(List_length(list) == 4);
		/* no need to free list2 any more */
	}

	{
		List_T list3;
		struct Foo* tmp;
		int expect[4] = {5, 4, 1, 2}, i = 0;

		list3 = List_reverse(List_copy(list));
		/*
			2 1 4 5 -> 5 4 1 2
		*/
		while (list3) {
			list3 = List_pop(list3, (void**)&tmp);
			TEST_ASSERT(tmp->a == expect[i++]);
		}
		/* no need to free list3, all poped and freed */
	}
	List_free(&list);

	{
		List_T list4 = NULL;
		int i;
		struct Foo* p;
		for (i = 0; i < 5; i++) {
			NEW(p);
			p->a = i;
			list4 = List_push(list4, p);
		}

		List_map(list4, free_foo, NULL);
		List_free(&list4);
	}

	{
		char* expect[] = {"N1", "N2", "N3", "N4", "N5"};
		List_T list5 = List_list("N1", "N2", "N3", "N4", "N5", NULL);
		char** arr = (char**)List_toArray(list5, NULL);
		int i;

		for (i = 0; i < 5; i++) {
			TEST_ASSERT(0 == strcmp(expect[i], arr[i]));
		}

		FREE(arr);
		List_free(&list5);
	}
}
