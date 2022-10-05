#include "Stack.h"

//初始化
void StackInit(ST* ps) {
	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL) {
		printf("realloc fail\n");
		exit(-1);
	} 
	
	//初始的top栈顶为0，则top指向的是栈顶的下一个元素
	//初始的top栈顶为-1，则top指向的是栈顶的元素
	ps->top = 0;
	ps->capacity = 2;
}
//销毁
void StackDestroy(ST* ps) {
	assert(ps);
	free(ps->a);
	ps -> a = NULL;
	ps->top = ps->capacity = 0;
}
//入栈
void StackPush(ST* ps, STDataType x) {
	assert(ps);
	//要考虑扩容
	if (ps->top == ps->capacity) {
		STDataType* tmp = (STDataType*)realloc(ps->a, (size_t)ps->capacity * 2 * sizeof(STDataType));
		if (tmp != NULL) {
			ps->a = tmp;
			ps->capacity *= 2;
		}
		else {
			printf("realloc fail\n");
			exit(-1);
		}
	}
	
	ps->a[ps->top] = x;
	ps->top++;
}
//出栈
void StackPop(ST* ps) {
	assert(ps);
	assert(ps->top > 0);  //栈非空才可以删除
	ps->top--;
}
//返回栈顶元素
STDataType StackTop(ST* ps) {
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top -1];
}
//返回栈的元素个数
int StackSize(ST* ps) {
	assert(ps);

	return ps->top;
}
//判断是否非空
bool StackEmpty(ST* ps) {
	assert(ps);
	return ps->top == 0;
}