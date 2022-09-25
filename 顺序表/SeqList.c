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

}
//销毁顺序表
void SeqListDestory(SL* ps) {
	free(ps->a);
	ps->a == NULL;
	ps->capacity = ps->size = 0;
}
//实现尾插
void SeqListPushBack(SL* ps, SLDataType x) {
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
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SL* ps, SLDataType x);
//实现尾删
void SeqListPopBack(SL* ps) {
	if (ps->size == 0) {
		printf("顺序表无元素！\n");
		return;
	}

	ps->size--;
}
void SeqListPopFront(SL* ps);