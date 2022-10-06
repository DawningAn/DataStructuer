# define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
//��ʼ��
void QueueInit(Queue* pq) {
	assert(pq);
	pq->head = pq->tail = NULL;
}
//����
void QueueDestroy(Queue* pq) {
	assert(pq);
	QNode* cur = pq->head;
	while (cur) {
		QNode* next = cur->next;
		free(cur);
		cur = next;
	
	}
	pq->head = pq->tail = NULL;
}
void QueuePrint(Queue* pq) {
	assert(pq);
	assert(pq->head);
	QNode* cur = pq->head;
	while (cur) {
		printf("%d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}
//��β��
void QueuePush(Queue* pq, QDataType x) {
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL) {
		printf("malloc fail\n");
		exit(-1);
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->tail == NULL) {
		pq->head = pq->tail = newnode;
	}
	else {  //β��
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}  
//��ͷ��
void QueuePop(Queue* pq) {
	assert(pq);
	assert(pq->head);
	//��ֻ��һ���ڵ�ʱ
	if (pq->head->next == NULL) {
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else {
		QNode* tmp = pq->head->next;  //����ͷ�ڵ����һ��
		free(pq->head);
		pq->head = tmp;
	}
	
}
//ȡ��ͷ�Ͷ�β
QDataType QueueFront(Queue* pq) {
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}
QDataType QueueBack(Queue* pq) {
	assert(pq);
	assert(pq->head);

	return pq->tail->data;
}
//�ж�Ϊ��
bool QueueEmpty(Queue* pq) {
	assert(pq);
	return pq->head == NULL;
}
//����Ԫ�ظ���
int QueueSize(Queue* pq) {
	assert(pq);
	int size = 0;
	QNode* cur = pq->head;
	while (cur) {
		size++;
		cur = cur->next;
	}
	return size;
}

