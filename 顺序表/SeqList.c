# define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//实现顺序表初始化
void SeqListInit(SL* ps) {
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//打印函数
void SeqListPrint(SL* ps) {
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}
	printf("\n");

}
//销毁顺序表
void SeqListDestory(SL* ps) {
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
//检查顺序表容量
void Check_capacity(SL* ps) {
	if (ps->size == ps->capacity) {
		//如果没有空间，那么要初始化
		//或者如果空间满了要扩容
		//printf("当前空间已满！");  //这时候要扩容
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;  //考虑一开始就没有空间的情况
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));

		if (tmp == NULL) {
			printf("realloc fail\n");
			exit(-1);
		}
		//如果开辟空间成功，就将临时空间赋给原数据指针
		ps->a = tmp;
		ps->capacity = newcapacity;

	}
}
//实现尾插
void SeqListPushBack(SL* ps, SLDataType x) {

	Check_capacity(ps);
	
	ps->a[ps->size] = x;
	ps->size++;
}
//实现头插
void SeqListPushFront(SL* ps, SLDataType x) {

	Check_capacity(ps);
	//用尾部标识挪动数据
	int end = ps->size - 1;
	while (end >= 0) {
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}
//实现尾删
void SeqListPopBack(SL* ps) {
	if (ps->size == 0) {
		printf("顺序表无元素！\n");
		return;
	}

	ps->size--;
}
//实现头删
void SeqListPopFront(SL* ps) {
	assert(ps->size > 0);
	int begin = 1;
	if (ps->size != 0) {
		while (begin < ps->size) {
			ps->a[begin - 1] = ps->a[begin];
			begin++;
		}
		ps->size--;
	}
}
//查找值的位置，返回下标,找不到返回-1
int SeqListFind(SL* ps, SLDataType x) {
	for (int i = 0; i < ps->size; i++) {
		if (ps->a[i] == x) {
			return i;
		}
	}
	return -1;
}
// 在某个位置（pos）插入元素x
void SeqListInsert(SL* ps, int pos, SLDataType x) {
	assert(pos < ps->size);
	int end = ps->size - 1;
	while (end >= pos) {
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}
//删除pos位置的数据
void SeqListEraser(SL* ps, int pos) {
	assert(pos < ps->size);
	int tmp = pos;
	while (tmp < ps->size - 1) {
		ps->a[tmp] = ps->a[tmp + 1];
		tmp++;
	}
	ps->size--;
}