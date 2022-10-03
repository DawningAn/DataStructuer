# define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

//�����ڵ�
ListNode* CreateNode(LTDataType x) {
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}
//��ʼ��
ListNode* ListInit() {
	ListNode* phead = CreateNode(0);
	//��ʼ��ʱ��Ҫָ��ͷ�ڵ�
	phead->next = phead;
	phead->prev = phead;

	return phead;
}
//����˫������
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
// ��ӡ˫��ѭ������
void ListPrint(ListNode* phead) {
	ListNode* cur = phead->next;
	while (cur != phead) {
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//ͷ��
void ListPushFront(ListNode* phead,LTDataType x) {
	assert(phead);
	ListNode* newnode = CreateNode(x);

	ListNode* first = phead->next;

	first -> prev = newnode;
	newnode->prev = phead;
	newnode->next = first;
	phead->next = newnode;
	

}
//β��
void ListPushBack(ListNode* phead, LTDataType x) {
	ListNode* newnode = CreateNode(x);

	//�����������ǿ��Խ����ǰ����Ϊ�յ����
	ListNode* tail = phead->prev;
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}
//ͷɾ
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
//βɾ
void ListPopBack(ListNode* phead) {
	assert(phead);

	ListNode* tail = phead->prev;

	tail->prev->next = phead;
	phead->prev = tail->prev;

	free(tail);
	tail = NULL;
}
//����
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
//����Ԫ��
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
//ɾ��Ԫ��
void ListEraser(ListNode* phead,LTDataType x) {
	ListNode* pos = ListFind(phead, x);
	if (pos) {
		pos->prev->next = pos->next;
		pos->next->prev = pos->prev;
		free(pos);
	}
}
//�ж������Ƿ�Ϊ��
int isEmpyt(ListNode* phead) {
	if (phead->next == phead)
		return 1;
	else
		return 0; 
}
//�������
int ListSize(ListNode* phead) {
	int count = 0;
	ListNode* cur = phead->next;
	while (cur != phead) {
		count++;
		cur = cur->next;
	}
	
	return count;
}
