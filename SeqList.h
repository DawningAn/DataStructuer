# define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#define N 1000
//���ں����������ͣ��޸�int����
typedef int SLDataType;

//����˳���(��������ΪSL����˳���)
typedef struct SeqList {
	SLDataType a[N];
	int size;
}SL;
//�ӿں���
void SeqListinit(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);
