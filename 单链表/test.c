# define _CRT_SECURE_NO_WARNINGS 1
#include "SList.h"
void menu() {
	printf("------------------------------------------\n");
	printf("----------1.ͷ��          2.β��----------\n");
	printf("----------3.ͷɾ          4.βɾ----------\n");
	printf("----------5.����          6.ɾ��----------\n");
	printf("----------7.����          0.�˳�----------\n");
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
	////���ҵ�һ��Ԫ�أ��ٲ���
	//SLTNode* pos = SListFind(phead, 3);
	//SListInsert(&phead, pos, 100);
	//SListPrint(phead);
	////10-->100-->3-->NULL
	////ɾ��10
	//SListEraser(&phead, 10);
	//SListPrint(phead);

	
	while (1) {
		menu();
		int input;
		printf("���������ѡ��");
		scanf("%d", &input);
		int x;
		int tmp;  //����ʱ��Ҫ�õ��Ĵ�����Ԫ��
		switch (input)
		{
		case 1:
			printf("������Ҫ�����Ԫ�أ�");
			scanf("%d", &x);
			SListPushFront(&phead, x);
			SListPrint(phead);
			break;
		case 2:
			printf("������Ҫ�����Ԫ�أ�");
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
			//����
			printf("������Ҫ���ĸ�Ԫ�ز��룺");
			scanf("%d", &tmp);
			SLTNode* pos = SListFind(phead, tmp);
			//printf("%d", pos->data);
			if (pos) {
				printf("������Ҫ�����Ԫ�أ�");
				scanf("%d", &x);
				SListInsert(&phead, pos, x);
			}
			SListPrint(phead);
			break;
		case 6:
			//ɾ��
			printf("������Ҫɾ����Ԫ�أ�");
			scanf("%d", &x);
			SListEraser(&phead, x);
			SListPrint(phead);
			break;
		case 7 :
			printf("������Ҫ���ҵ�Ԫ�أ�");
			scanf("%d", &tmp);
			pos = SListFind(phead, tmp);
			if (pos) {
				printf("%d\n", pos->data);
			}
			SListPrint(phead);
			break;
		case 0:
			printf("�˳���\n");
			exit(0);
		default:
			break;
		}
	}
	

	return 0;
}