# define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
//��ʧ������
//����nums������0��n������������������ȱ��һ�������д�����ҳ��Ǹ�ȱʧ�����������а취��O(n)ʱ���������
//int main() {
//    //�����������
//    int arr[9] = { 1,2,3,5,6,7,8,9 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//
//    int x = 0;  //x���������Ƽ���������ʧ������
//    //�Ⱥ�������ȱ���ֵ�����ȫ�����
//    for (int i = 0; i <= sz; i++) {
//        x ^= i;
//    }
//    //�ٺ���Ҫ����������������
//    for (int i = 0; i < sz; i++) {
//        x = x ^ arr[i];
//    }
//    printf("%d\n", x);  //��ӡ����ʧ������
//}

//ʵ��˳���
void TestSeqList1() {
	SL sl;
	SeqListInit(&sl);  //��ַ���κ���Ҫ���β���ʵ�ε���ʱ���������βε��޸Ĳ���ı�ʵ��

	//ʵ�ֲ�������
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	SeqListPrint(&sl);

	//������˾�����
	SeqListDestory(&sl);

}

void TestSeqList2() {
	SL s2;
	SeqListInit(&s2);

	SeqListPushBack(&s2, 1);
	SeqListPushBack(&s2, 2);
	SeqListPushBack(&s2,3);
	SeqListPushBack(&s2, 4);
	SeqListPushBack(&s2, 5);

	SeqListPushFront(&s2,1);
	SeqListPushFront(&s2,2);
	SeqListPushFront(&s2,3);
	SeqListPushFront(&s2,4);
	SeqListPushFront(&s2,5);

	SeqListPrint(&s2);

	SeqListPopFront(&s2);
	SeqListPopFront(&s2);

	SeqListPrint(&s2);
	SeqListPushBack(&s2, 9);
	int ret = SeqListFind(&s2, 9);
	printf("%d\n", ret);

	SeqListInsert(&s2, 2, 10);
	SeqListPrint(&s2);
	SeqListEraser(&s2, 1);
	SeqListPrint(&s2);




	//������˾�����
	SeqListDestory(&s2);
}
void menu() {
	printf("-------------------------------------------\n");
	printf("--------1.ͷ��----------------2.β��--------\n");
	printf("--------3.ͷɾ----------------4.βɾ--------\n");
	printf("--------5.����----------------6.����Ԫ��----\n");
	printf("--------7.ɾ��ָ��Ԫ��---------0.�˳�--------\n");
	printf("-------------------------------------------\n");
}
enum Option {
	Exit,
	SLPushFront,
	SLPushBack,
	SLPopFront,
	SLPopBack,
	SLFind,
	SLInsert,
	SLEraser


};
int main() {
	//TestSeqList1();
	//TestSeqList2();
	//ʵ�ֽ���������˳���
	SL s;
	SeqListInit(&s);
	while (1) {
		menu();
		printf("�����������");
		int input;
		scanf("%d", &input);
		int x;
		int pos;
		switch (input)
		{
		case SLPushFront:
			printf("�������������֣�");
			scanf("%d", &x);
			SeqListPushFront(&s, x);
			SeqListPrint(&s);
			break;
		case SLPushBack:
			printf("�������������֣�");
			scanf("%d", &x);
			SeqListPushBack(&s, x);
			SeqListPrint(&s);
			break;
		case SLPopFront:
			SeqListPopFront(&s);
			SeqListPrint(&s);
			break;
		case SLPopBack:
			SeqListPopBack(&s);
			SeqListPrint(&s);
			break;
		case SLFind:
			printf("������Ҫ���ҵ����֣�");
			scanf("%d", &x);
			SeqListFind(&s, x);
			SeqListPrint(&s);
			break;
		case SLInsert:
			printf("������Ҫ�����λ�ü�Ԫ�أ�");
			scanf("%d %d", &pos, &x);
			SeqListInsert(&s, pos, x);
			SeqListPrint(&s);
			break;
		case SLEraser:
			printf("������Ҫɾ����λ�ã�");
			scanf("%d", &pos);
			SeqListEraser(&s, pos);
			SeqListPrint(&s);
			break;
		case Exit:
			printf("�˳���\n");
			exit(0);
		default:
			printf("�Ƿ����룡\n");
			break;
		}
	}
	return 0;
}