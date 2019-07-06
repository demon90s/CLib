#ifndef TABLE_H
#define TABLE_H

#define T Table_T

typedef struct T *T;

/* functions */

/*
	hint 用于估计新的表中预期会容纳的表项数目，用于提高性能
	cmp 和 hash 负责操作特定于客户程序的键
	如果 hash 是NULL，Table提供一个适当的哈希函数
	如果 cmp 是NULL，那么假定表的键为原子
*/
extern T Table_new(int hint,
				   int cmp(const void *x, const void *y),
				   unsigned hash(const void *key));

/*
	释放掉 *table , 并设置 table 为NULL
*/
extern void Table_free(T *table);

/*
	返回table中键值对的数量
*/
extern int Table_length(T table);

/*
	将 key-value 添加到table
	如果table已经包含了 key ，那么用 value 覆盖掉原来的值，Table_put 返回此前的值
	否则，增加一个表项，并返回 NULL
*/
extern void *Table_put(T table, const void *key, void *value);

/*
	在 table 中查找 key ，如果找到，返回关联的值
	否则返回 NULL
*/
extern void *Table_get(T table, const void *key);

/*
	在 table 中查找 key ，如果找到则删除对应的键值对，并返回被删除的值
	没找到，则返回 NULL
*/
extern void *Table_remove(T table, const void *key);

/*
	以未指定的顺序对 table 中的每个键值对调用 apply 指向的函数
*/
extern void Table_map(T table,
					  void apply(const void *key, void **value, void *cl),
					  void *cl);

/*
	将键值对收集到一个数组中
	对一个给定包含N个键值对的表，数组会有2N+1个元素
	返回第一个数组元素的指针
	数组中，键和值交替出现，键出现在偶数编号，下一个奇数编号是其对应的值
	最后一个偶数编号的元素位于索引2N处，被赋值为 end
*/
extern void **Table_toArray(T table, void *end);

#endif
