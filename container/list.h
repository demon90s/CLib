#ifndef LIST_H
#define LIST_H

#define T List_T

/*
	List_T 是一个指向某个 struct List_T 实例的指针
	NULL代表空链表
*/
typedef struct T* T;

struct T {
	T rest;
	void* first;
};

/*
	将tail赋值给list中最后一个结点的rest字段
*/
extern T List_append(T list, T tail);

/*
	复制list，并返回其副本
*/
extern T List_copy(T list);

/*
	创建并返回一个链表
	最后一个（第N+1个）指针参数为NULL
	函数创建一个包含N个结点的链表
*/
extern T List_list(void* x, ...);

/*
	将第一个结点的 first 字段赋值给*x（如果x不是NULL）
	移除第一个结点并释放其内存，最后返回结果链表
*/
extern T List_pop(T list, void** x);

/*
	在链表list的起始处添加一个包含x的新结点，并返回新链表
*/
extern T List_push(T list, void* x);

/*
	逆转list中结点的顺序，然后返回结果链表
*/
extern T List_reverse(T list);

/*
	返回list中结点数目
*/
extern int List_length(T list);

/*
	释放*list中所有结点并将其设置为NULL指针
*/
extern void List_free(T* list);

/*
	对list中的每个结点调用apply指向的函数
*/
extern void List_map(T list, void apply(void** x, void* cl), void* cl);

/*
	创建一个数组，数组元素[0-N-1]分别包含链表中N个结点的first字段值
	返回指向数组第一个元素的指针
*/
extern void** List_toArray(T list, void* end);

#undef T

#endif /* LIST_H */
