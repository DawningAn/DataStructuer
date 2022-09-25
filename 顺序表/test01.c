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

}
int main() {
	TestSeqList1();
	return 0;
}