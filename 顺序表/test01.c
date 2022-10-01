# define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"
//消失的数字
//数组nums包含从0到n的所有整数，但其中缺了一个。请编写代码找出那个缺失的整数。你有办法在O(n)时间内完成吗？
//int main() {
//    //考虑异或特性
//    int arr[9] = { 1,2,3,5,6,7,8,9 };
//    int sz = sizeof(arr) / sizeof(arr[0]);
//
//    int x = 0;  //x变量来控制检索最终消失的数字
//    //先和完整不缺数字的数字全部异或
//    for (int i = 0; i <= sz; i++) {
//        x ^= i;
//    }
//    //再和需要检索的数组进行异或
//    for (int i = 0; i < sz; i++) {
//        x = x ^ arr[i];
//    }
//    printf("%d\n", x);  //打印出消失的数字
//}

//实现顺序表
void TestSeqList1() {
	SL sl;
	SeqListInit(&sl);  //地址传参很重要，形参是实参的临时拷贝，对形参的修改不会改变实参

	//实现插入数据
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);

	SeqListPrint(&sl);

	//最后不用了就销毁
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




	//最后不用了就销毁
	SeqListDestory(&s2);
}
void menu() {
	printf("-------------------------------------------\n");
	printf("--------1.头插----------------2.尾插--------\n");
	printf("--------3.头删----------------4.尾删--------\n");
	printf("--------5.查找----------------6.插入元素----\n");
	printf("--------7.删除指定元素---------0.退出--------\n");
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
	//实现交互来测试顺序表
	SL s;
	SeqListInit(&s);
	while (1) {
		menu();
		printf("请输入操作：");
		int input;
		scanf("%d", &input);
		int x;
		int pos;
		switch (input)
		{
		case SLPushFront:
			printf("请输入插入的数字：");
			scanf("%d", &x);
			SeqListPushFront(&s, x);
			SeqListPrint(&s);
			break;
		case SLPushBack:
			printf("请输入插入的数字：");
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
			printf("请输入要查找的数字：");
			scanf("%d", &x);
			SeqListFind(&s, x);
			SeqListPrint(&s);
			break;
		case SLInsert:
			printf("请输入要插入的位置及元素：");
			scanf("%d %d", &pos, &x);
			SeqListInsert(&s, pos, x);
			SeqListPrint(&s);
			break;
		case SLEraser:
			printf("请输入要删除的位置：");
			scanf("%d", &pos);
			SeqListEraser(&s, pos);
			SeqListPrint(&s);
			break;
		case Exit:
			printf("退出！\n");
			exit(0);
		default:
			printf("非法输入！\n");
			break;
		}
	}
	return 0;
}