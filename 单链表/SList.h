# define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//指针域和数据域
typedef int SLTDataType;
typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;  //指针是指向下一个节点
}SLTNode;

void SListPrint(SLTNode* phead);
//头插
void SListPushFront(SLTNode** phead, SLTDataType x);
//尾插
void SListPushBack(SLTNode** phead, SLTDataType x);
// 头删
void SListPopFront(SLTNode** phead);
// 尾删
void SListPopBack(SLTNode** phead);
// 插入
// 删除
// 查找