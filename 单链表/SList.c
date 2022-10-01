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

	
}