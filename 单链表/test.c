# define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void menu() {
	printf("------------------------------------------\n");
	printf("----------1.头插          2.尾插----------\n");
	printf("----------3.头删          4.尾删----------\n");
	printf("----------5.插入          6.删除----------\n");
	printf("----------7.查找          0.退出----------\n");
	printf("------------------------------------------\n");
	
}
int main() {
	SLTNode* phead = NULL;

	//SListPushBack(&phead,10);
	//SListPushBack(&phead,3);
	//SListPushFront(&phead,4);
	//SListPrint(phead);
	//SListPushBack(&phead, 20);
	//SListPrint(phead);
	//SListPopFront(&phead);
	//SListPopBack(&phead);

	//SListPrint(phead);
	////先找到一个元素，再插入
	//SLTNode* pos = SListFind(phead, 3);
	//SListInsert(&phead, pos, 100);
	//SListPrint(phead);
	////10-->100-->3-->NULL
	////删除10
	//SListEraser(&phead, 10);
	//SListPrint(phead);

	
	while (1) {
		menu();
		int input;
		printf("请输入你的选择：");
		scanf("%d", &input);
		int x;
		int tmp;  //查找时需要用到的待查找元素
		switch (input)
		{
		case 1:
			printf("请输入要插入的元素：");
			scanf("%d", &x);
			SListPushFront(&phead, x);
			SListPrint(phead);
			break;
		case 2:
			printf("请输入要插入的元素：");
			scanf("%d", &x);
			SListPushBack(&phead, x);
			SListPrint(phead);
			break;
		case 3:
			SListPopFront(&phead);
			SListPrint(phead);
			break;
		case 4:
			SListPopBack(&phead);
			SListPrint(phead);
			break;
		case 5:
			//插入
			printf("请输入要在哪个元素插入：");
			scanf("%d", &tmp);
			SLTNode* pos = SListFind(phead, tmp);
			//printf("%d", pos->data);
			if (pos) {
				printf("请输入要插入的元素：");
				scanf("%d", &x);
				SListInsert(&phead, pos, x);
			}
			SListPrint(phead);
			break;
		case 6:
			//删除
			printf("请输入要删除的元素：");
			scanf("%d", &x);
			SListEraser(&phead, x);
			SListPrint(phead);
			break;
		case 7 :
			printf("请输入要查找的元素：");
			scanf("%d", &tmp);
			pos = SListFind(phead, tmp);
			if (pos) {
				printf("%d\n", pos->data);
			}
			SListPrint(phead);
			break;
		case 0:
			printf("退出！\n");
			exit(0);
		default:
			break;
		}
	}
	

	return 0;
}