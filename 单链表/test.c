# define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
int main() {
	SLTNode* phead = NULL;

	SListPushBack(&phead,10);
	SListPushBack(&phead,3);
	SListPushFront(&phead,4);
	SListPrint(phead);
	SListPushBack(&phead, 20);
	SListPrint(phead);
	SListPopFront(&phead);
	SListPopBack(&phead);
	SListPrint(phead);
	//���ҵ�һ��Ԫ�أ��ٲ���
	SLTNode* pos = SListFind(phead, 3);
	SListInsert(&phead, pos, 100);
	SListPrint(phead);
	//10-->100-->3-->NULL
	//ɾ��10
	SListEraser(&phead, 10);
	SListPrint(phead);

	return 0;
}