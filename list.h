#ifndef LIST_H
#define LIST_H

typedef struct ListNode_ {
	void *value;			// dynamic obj
	struct ListNode_* next;
} ListNode;

// 创建链表，成功返回头指针，失败返回NULL
ListNode* list_init();

// 销毁链表
void list_destroy(ListNode* header);

// 设置值（value为用户动态分配的）
void list_setvalue(ListNode* node, void* value);

// 追加节点，返回此追加的节点，失败返回NULL
ListNode* list_pushback(ListNode* header, void* value);

// 插入节点（在prenode之后插），返回此插入的节点，失败返回NULL
ListNode* list_insert(ListNode* prenode, void* value);

// 删除节点，使用cmp作为匹配算法（算法返回0表示匹配），返回头结点
typedef int (*cmp_function)(void *v1, void *v2);
ListNode* list_remove(ListNode *header, void *value, cmp_function cmp);

// 排序链表，使用cmp作为匹配算法（算法返回大于0则v1往后排）
void list_sort(ListNode *header, cmp_function cmp);

// 获得list长度
int list_size(ListNode *header);

#endif // LIST_H
