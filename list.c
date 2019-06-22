#include "list.h"
#include <stdlib.h>

typedef struct ListNode_
{
	void *value;				/* point to dynamic obj */
	struct ListNode_ *next;
} ListNode;

ListNode *list_init()
{
	ListNode *node = (ListNode *) malloc(sizeof(ListNode));
	if (node == NULL)
		return NULL;

	node->value = NULL;
	node->next = NULL;

	return node;
}

void list_destroy(ListNode * header)
{
	ListNode *p = header;
	ListNode *next;

	while (p != NULL)
	{
		if (p->value != NULL)
			free(p->value);

		next = p->next;
		free(p);
		p = next;
	}
}

void *list_getvalue(ListNode * node)
{
	return node->value;
}

void list_setvalue(ListNode * node, void *value)
{
	if (node->value != NULL)
		free(node->value);

	node->value = value;
}

ListNode *list_pushback(ListNode * header, void *value)
{
	ListNode *node;
	ListNode *last = header;

	while (last->next != NULL)
	{
		last = last->next;
	}

	node = (ListNode *) malloc(sizeof(ListNode));
	node->value = value;
	node->next = NULL;

	last->next = node;

	return node;
}

ListNode *list_insert(ListNode * prenode, void *value)
{
	ListNode *node;
	ListNode *next = prenode->next;

	node = (ListNode *) malloc(sizeof(ListNode));
	node->value = value;
	node->next = next;

	prenode->next = node;

	return node;
}

ListNode *list_remove(ListNode * header, void *value, cmp_function cmp)
{
	ListNode *next = header->next;
	ListNode *pre = header;

	/* Check header */
	if (pre->value && cmp(value, pre->value) == 0)
	{
		free(pre->value);
		free(pre);
		return next;
	}

	while (next != NULL)
	{
		if (next->value && cmp(value, next->value) == 0)
		{
			pre->next = next->next;

			free(next->value);
			free(next);
			break;
		}

		pre = next;
		next = next->next;
	}

	return header;
}

ListNode *list_search(ListNode * header, void *value, cmp_function cmp)
{
	ListNode *p;

	p = header;
	while (p != NULL)
	{
		if (cmp(p->value, value) == 0)
			break;

		p = p->next;
	}

	return p;
}

void list_sort(ListNode * header, cmp_function cmp)
{
	/* bubble sort */
	ListNode *p, *q;
	void *tmp_v;

	for (p = header; p->next != NULL; p = p->next)
	{
		for (q = p->next; q != NULL; q = q->next)
		{
			if (cmp(p->value, q->value) > 0)
			{
				tmp_v = p->value;
				p->value = q->value;
				q->value = tmp_v;
			}
		}
	}
}

int list_size(ListNode * header)
{
	int sz = 0;
	ListNode *p = header;

	while (p != NULL)
	{
		sz++;
		p = p->next;
	}

	return sz;
}

ListNode *list_next(ListNode * node)
{
	return node->next;
}
