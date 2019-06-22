#include "test_list.h"
#include <stdio.h>
#include <stdlib.h>

static void test_print_list(ListNode* header)
{
	ListNode* p;

	p = header;
	while (p != NULL) {
		printf("%d ", *(int*) (list_getvalue(p)));
		p = list_next(p);
	}
	printf("\n");
}

static int test_cmp_int(void* v1, void* v2)
{
	int* p1 = v1;
	int* p2 = v2;
	return *p2 - *p1;
}

void test_list()
{
	ListNode* header = list_init();
	int i;
	int* value;

	value = (int*) malloc(sizeof(int));
	*value = 1;
	list_setvalue(header, value);

	for (i = 0; i < 10; i++) {
		value = (int*) malloc(sizeof(int));
		*value = i + 100;
		list_pushback(header, value);
	}

	test_print_list(header);

	value = (int*) malloc(sizeof(int));
	*value = 1000;
	list_insert(header, value);

	test_print_list(header);

	value = (int*) malloc(sizeof(int));
	*value = 105;
	header = list_remove(header, value, test_cmp_int);
	*value = 1;
	header = list_remove(header, value, test_cmp_int);
	*value = 109;
	header = list_remove(header, value, test_cmp_int);
	free(value);

	test_print_list(header);

	list_sort(header, test_cmp_int);

	test_print_list(header);

	printf("list size: %d\n", list_size(header));

	value = (int*) malloc(sizeof(int));
	*value = 105;
	if (NULL != list_search(header, value, test_cmp_int)) {
		printf("find value %d\n", *value);
	}
	else {
		printf("Not found value: %d\n", *value);
	}
	free(value);

	list_destroy(header);
}
