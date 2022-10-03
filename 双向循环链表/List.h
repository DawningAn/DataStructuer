# define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//�����ڱ�ͷ�ڵ�� ˫������
typedef int LTDataType;

typedef struct ListNode {
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;
//��ӡ����
void ListPrint(ListNode* phead);
//��ʼ������
ListNode* ListInit();
//��������
void ListDestory(ListNode* phead);

//ͷ��
void ListPushFront(ListNode* phead, LTDataType x);
//β��
void ListPushBack(ListNode* phead, LTDataType x);
//ͷɾ
void ListPopFront(ListNode* phead);
//βɾ
void ListPopBack(ListNode* phead);
//����
ListNode* ListFind(ListNode* phead, LTDataType x);
//����
void ListInsert(ListNode* phead, LTDataType tmp, LTDataType x);
//ɾ��
void ListEraser(ListNode* phead, LTDataType x);
//�ж������Ƿ�Ϊ��
int isEmpyt(ListNode* phead);
//�������
int ListSize(ListNode* phead);
