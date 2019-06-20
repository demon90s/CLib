#ifndef LIST_H
#define LIST_H

/* compare the obj pointed by v1 and v2, return 0 if equal, greater then 0 if v1 > v2, else v1 < v2 */
typedef int (*cmp_function)(void *v1, void *v2);

typedef struct ListNode_ ListNode;

/* create list, return header node, NULL if failed */
ListNode* list_init();

/* destroy list, free all value */
void list_destroy(ListNode* header);

/* get the node value */
void* list_getvalue(ListNode* node);

/* set value to node, old value will be free */
void list_setvalue(ListNode* node, void* value);

/* add a new node to the back, return this node */
ListNode* list_pushback(ListNode* header, void* value);

/* insert a node after prenode, return this node */
ListNode* list_insert(ListNode* prenode, void* value);

/* remove the node which value is given, return header node, you should assign it to the header */
ListNode* list_remove(ListNode *header, void *value, cmp_function cmp);

/* search the node which value is given, return found node, NULL if not found  */
ListNode* list_search(ListNode *header, void *value, cmp_function cmp);

/* sort the list by given sort function */
void list_sort(ListNode *header, cmp_function cmp);

/* return the list size, empty list return 0 */
int list_size(ListNode *header);

/* return next node */
ListNode* list_next(ListNode *node);

#endif /* LIST_H */
