# define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define N 1000
//���ں����������ͣ��޸�int����
typedef int SLDataType;

//����˳���(��������ΪSL����˳���)
//typedef struct SeqList {
//	SLDataType a[N];
//	int size;		//�����д���˶��ٸ�����
//	int	capacity;  //����ʵ���ܴ�ŵĿռ�����
//}SL;

//���Ƕ�̬����˳���
typedef struct SeqList {
	SLDataType* a;
	int size;
	int capacity;
}SL;
//�ӿں���
void SeqListInit(SL* ps);
void SeqListPushFront(SL* ps, SLDataType x);
void SeqListPushBack(SL* ps, SLDataType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);
//����ֵ��λ�ã������±�
void SeqListFind(SL* ps, SLDataType x);
// ��ĳ��λ�ò���Ԫ��x
void SeqListInsert(SL* ps, int pos, SLDataType x);
//ɾ��posλ�õ�����
void SeqListErase(SL* ps, int pos);
//�������
void Check_capacity(SL* ps);
//��ӡ˳���
void SeqListPrint(SL* ps);
//����˳���
void SeqListDestory(SL* ps);
