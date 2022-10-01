# define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//遍历打印
void SListPrint(SLTNode* phead) {
	SLTNode* cur = phead;
	while (cur) {
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//创建节点
SLTNode* CreateNode(SLTDataType x) {
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;
	return node;
}
//尾插
void SListPushBack(SLTNode** pphead, SLTDataType x) {
	//尾插肯定要找到尾部
	//先定义好要插入的这个节点
	
	SLTNode* newnode = CreateNode(x);
	//还要检查当前链表是否为空
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else {
		//定义一个尾节点，并且去找到它
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//将新插入的节点连接上去
		tail->next = newnode;
	}
	
}

//头插
void SListPushFront(SLTNode** pphead, SLTDataType x) {
	//初始化一个节点
	SLTNode* newnode = CreateNode(x);
	
	newnode->next = *pphead;
	*pphead = newnode;
}
//头删
void SListPopFront(SLTNode** pphead) {

	
}