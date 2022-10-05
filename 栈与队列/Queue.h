# define _CRT_SECURE_NO_WARNINGS 1
#pragma once
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

void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);  //队尾入
void QueuePop(Queue* pq);  //队头出
//取队头和队尾
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);