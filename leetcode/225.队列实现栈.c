#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
typedef int QDataType;

typedef struct QueueNode {
	//单链表实现队列
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue {
	QNode* head;
	QNode* tail;
}Queue;
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
	while (cur != pq->tail) {
		size++;
	}
	return size + 1;
}


typedef struct {
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate() {
    MyStack* ps = (MyStack*)malloc(sizeof(MyStack));
	if(ps == NULL){
		printf("malloc fail\n");
		exit(-1);
	}
	QueueInit(&ps->q1);
	QueueInit(&ps->q2);
	return ps;
}

void myStackPush(MyStack* obj, int x) {
	if(!QueueEmpty(&obj->q1)){
		QueuePush(&obj->q1,x);
	}else{
		QueuePush(&obj->q2,x);
	}
}

int myStackPop(MyStack* obj) {
	Queue* emptyQ = &obj->q1;
	Queue* nonemptyQ = &obj->q2;
	if(!QueueEmpty(&obj->q1)){
		emptyQ = &obj->q2;
		nonemptyQ = &obj->q1;
	}

	while(QueueSize(nonemptyQ) > 1){
		QueuePush(emptyQ,QueueFront(nonemptyQ));
		QueuePop(nonemptyQ); 
	}
	int top =  QueueFront(nonemptyQ);
	//剩余一个数据，就是要删除的
	QueuePop(nonemptyQ);
	return top;
}

int myStackTop(MyStack* obj) {
	if(!QueueEmpty(&obj->q1)){
		return QueueBack(&obj->q1);
	}else{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) {
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);
	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/