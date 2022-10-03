# define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"
void Test1() {
	
	ListNode* plist = ListInit();

	printf("%d\n",isEmpyt(plist));
	printf("Size：%d\n",ListSize(plist));
	ListPushBack(plist, 10);
	ListPushBack(plist, 1);
	ListPushBack(plist, 20);
	ListPrint(plist);
	printf("Size：%d\n", ListSize(plist));


	ListPushFront(plist, 5);
	ListPushFront(plist, 55);
	ListPrint(plist);
	printf("Size：%d\n", ListSize(plist));


	ListEraser(plist, 20);
	ListPrint(plist);
	printf("Size：%d\n", ListSize(plist));
	printf("%d\n", isEmpyt(plist));

	ListInsert(plist, 5, 6);
	ListPrint(plist);
	printf("Size：%d\n", ListSize(plist));




	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPopBack(plist);
	ListPrint(plist);
	printf("Size：%d\n", ListSize(plist));
	printf("%d\n", isEmpyt(plist));


	ListNode* pos = ListFind(plist, 200);
	if (pos) {
		printf("找到了！\n");
		//也可以添加修改功能
		pos->data = 100;
	}
	else {
		printf("未找到！\n");
	}

	ListDestory(plist);
	
}
int main() {
	Test1();
	return 0;
}