# define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
//ָ�����������
typedef int SLTDataType;
typedef struct SListNode {
	SLTDataType data;
	struct SListNode* next;  //ָ����ָ����һ���ڵ�
}SLTNode;

void SListPrint(SLTNode* phead);
//ͷ��
void SListPushFront(SLTNode** phead, SLTDataType x);
//β��
void SListPushBack(SLTNode** phead, SLTDataType x);
// ͷɾ
void SListPopFront(SLTNode** phead);
// βɾ
void SListPopBack(SLTNode** phead);
// ����
// ɾ��
// ����