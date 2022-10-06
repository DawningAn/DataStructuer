# define _CRT_SECURE_NO_WARNINGS 1
#include "Queue.h"
//初始化
void QueueInit(Queue* pq) {
	assert(pq);
	pq->head = pq->tail = NULL;
}
//销毁
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
//队尾入
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
	else {  //尾插
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}  
//队头出
void QueuePop(Queue* pq) {
	assert(pq);
	assert(pq->head);
	//当只有一个节点时
	if (pq->head->next == NULL) {
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else {
		QNode* tmp = pq->head->next;  //保存头节点的下一个
		free(pq->head);
		pq->head = tmp;
	}
	
}
//取队头和队尾
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
//判断为空
bool QueueEmpty(Queue* pq) {
	assert(pq);
	return pq->head == NULL;
}
//队列元素个数
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

