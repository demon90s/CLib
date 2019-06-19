#ifndef LIST_H
#define LIST_H

typedef struct ListNode_ {
	void *value;			// dynamic obj
	struct ListNode_* next;
} ListNode;

// ���������ɹ�����ͷָ�룬ʧ�ܷ���NULL
ListNode* list_init();

// ��������
void list_destroy(ListNode* header);

// ����ֵ��valueΪ�û���̬����ģ�
void list_setvalue(ListNode* node, void* value);

// ׷�ӽڵ㣬���ش�׷�ӵĽڵ㣬ʧ�ܷ���NULL
ListNode* list_pushback(ListNode* header, void* value);

// ����ڵ㣨��prenode֮��壩�����ش˲���Ľڵ㣬ʧ�ܷ���NULL
ListNode* list_insert(ListNode* prenode, void* value);

// ɾ���ڵ㣬ʹ��cmp��Ϊƥ���㷨���㷨����0��ʾƥ�䣩������ͷ���
typedef int (*cmp_function)(void *v1, void *v2);
ListNode* list_remove(ListNode *header, void *value, cmp_function cmp);

// ��������ʹ��cmp��Ϊƥ���㷨���㷨���ش���0��v1�����ţ�
void list_sort(ListNode *header, cmp_function cmp);

// ���list����
int list_size(ListNode *header);

#endif // LIST_H
