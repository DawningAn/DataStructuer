# define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
typedef int QDataType;

typedef struct QueueNode {
	//������ʵ�ֶ���
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
void QueuePush(Queue* pq, QDataType x);  //��β��
void QueuePop(Queue* pq);  //��ͷ��
//ȡ��ͷ�Ͷ�β
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);