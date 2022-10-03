# define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//创建节点
ListNode* CreateNode(LTDataType x) {
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}
//初始化
ListNode* ListInit() {
	ListNode* phead = CreateNode(0);
	//初始化时都要指向头节点
	phead->next = phead;
	phead->prev = phead;

	return phead;
}
//销毁双向链表
void ListDestory(ListNode* phead) {
	assert(phead);
	ListNode* cur = phead->next;
	while (cur != phead) {
		ListNode* Next = cur->next;
		free(cur);
		cur = Next;
	}
	free(phead);
	phead = NULL;
}
// 打印双向循环链表
void ListPrint(ListNode* phead) {
	ListNode* cur = phead->next;
	while (cur != phead) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//头插
void ListPushFront(ListNode* phead,LTDataType x) {
	assert(phead);
	ListNode* newnode = CreateNode(x);

	ListNode* first = phead->next;

	first -> prev = newnode;
	newnode->prev = phead;
	newnode->next = first;
	phead->next = newnode;
	

}
//尾插
void ListPushBack(ListNode* phead, LTDataType x) {
	ListNode* newnode = CreateNode(x);

	//这样的做法是可以解决当前链表为空的情况
	ListNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}
//头删
void ListPopFront(ListNode* phead) {
	assert(phead);
	assert(phead->next != phead);

	ListNode* first = phead->next;
	ListNode* second = first->next;
	phead->next = second;
	second->prev = phead;

	free(first);
	first = NULL;
}
//尾删
void ListPopBack(ListNode* phead) {
	assert(phead);

	ListNode* tail = phead->prev;

	tail->prev->next = phead;
	phead->prev = tail->prev;

	free(tail);
	tail = NULL;
}
//查找
ListNode* ListFind(ListNode* phead, LTDataType x) {
	ListNode* cur = phead->next;
	while (cur!= phead) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//插入元素
void ListInsert(ListNode* phead, LTDataType tmp, LTDataType x) {
	ListNode* pos = ListFind(phead, tmp);
	if (pos) {
		ListNode* prev = pos->prev;

		ListNode* newnode = CreateNode(x);

		prev->next = newnode;
		newnode->next = pos;
		newnode->prev = prev;
		pos->prev = newnode;
	}
}
//删除元素
void ListEraser(ListNode* phead,LTDataType x) {
	ListNode* pos = ListFind(phead, x);
	if (pos) {
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		free(pos);
	}
}
//判断链表是否为空
int isEmpyt(ListNode* phead) {
	if (phead->next == phead)
		return 1;
	else
		return 0; 
}
//链表计数
int ListSize(ListNode* phead) {
	int count = 0;
	ListNode* cur = phead->next;
	while (cur != phead) {
		count++;
		cur = cur->next;
	}
	
	return count;
}
