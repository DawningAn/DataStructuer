# define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"

//������ӡ
void SListPrint(SLTNode* phead) {
	SLTNode* cur = phead;
	while (cur) {
		printf("%d-->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}
//�����ڵ�
SLTNode* CreateNode(SLTDataType x) {
	SLTNode* node = (SLTNode*)malloc(sizeof(SLTNode));
	node->data = x;
	node->next = NULL;
	return node;
}
//β��
void SListPushBack(SLTNode** pphead, SLTDataType x) {
	//β��϶�Ҫ�ҵ�β��
	//�ȶ����Ҫ���������ڵ�
	
	SLTNode* newnode = CreateNode(x);
	//��Ҫ��鵱ǰ�����Ƿ�Ϊ��
	if (*pphead == NULL) {
		*pphead = newnode;
	}
	else {
		//����һ��β�ڵ㣬����ȥ�ҵ���
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//���²���Ľڵ�������ȥ
		tail->next = newnode;
	}
	
}

//ͷ��
void SListPushFront(SLTNode** pphead, SLTDataType x) {
	//��ʼ��һ���ڵ�
	SLTNode* newnode = CreateNode(x);
	
	newnode->next = *pphead;
	*pphead = newnode;
}
//ͷɾ
void SListPopFront(SLTNode** pphead) {
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}
//βɾ
void SListPopBack(SLTNode** pphead) {
	//û�нڵ�
	if (*pphead == NULL)
		return;
	//ֻ��һ���ڵ�
	else if ((*pphead)->next == NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* back = *pphead;
		SLTNode* pre = NULL;
		while (back->next != NULL) {
			pre = back;
			back = back->next;
		}
		free(back);
		pre->next = NULL;
	}	
}
//����
SLTNode* SListFind(SLTNode* phead, SLTDataType x) {
	SLTNode* cur = phead;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
//����
void SListInsert(SLTNode** pphead, SLTNode* pos,SLTDataType x) {
	SLTNode* pre = *pphead;
	//���pos�ڵ�һ��λ�õ����
	if (pos == *pphead) {
		SListPushFront(pphead, x);
	}
	else {
		while (pre->next != pos) {
			pre = pre->next;
		}
		SLTNode* newnode = CreateNode(x);
		pre->next = newnode;
		newnode->next = pos;
	}
}
//ɾ��
void SListEraser(SLTNode** phead, SLTDataType x) {
	SLTNode* ret = SListFind(*phead, x);
	if (ret) {
		if (ret == *phead) {
			*phead = ret->next;
			free(ret);
		}
		else {
			SLTNode* pre = *phead;
			while (pre->next != ret) {
				pre = pre->next;
			}
			pre->next = ret->next;
			free(ret);
		}
		
	}
}
