# define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
int main() {
	SLTNode* phead = NULL;

	SListPushBack(&phead,10);
	SListPushBack(&phead,3);
	SListPushFront(&phead,4);
	SListPrint(phead);
}