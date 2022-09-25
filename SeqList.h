# define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#define N 1000
//便于后续多种类型，修改int即可
typedef int SLDataType;

//定义顺序表(重新命名为SL代表顺序表)
//typedef struct SeqList {
//	SLDataType a[N];
//	int size;		//数组中存放了多少个数据
//	int	capacity;  //数组实际能存放的空间容量
//}SL;

//考虑动态开辟顺序表
typedef struct SeqList {
	SLDataType* a;
	int size;
	int capacity;
}SL;
//接口函数
void SeqListInit(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);

void SeqListPrint(SL* ps);
