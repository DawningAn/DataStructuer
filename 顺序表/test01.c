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
int main() {
	//TestSeqList1();
	TestSeqList2();
	return 0;
}