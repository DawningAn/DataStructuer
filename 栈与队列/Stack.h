# define _CRT_SECURE_NO_WARNINGS 1
#pragma once  //防止头文件被重复包含
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
//栈显然可以用数组实现，也可以用链表（双向链表或单链表）实现

//选择数组来实现栈（CPU缓存命中更高）
typedef int STDataType;
typedef struct Stack {
	STDataType* a;
	//不使用静态的数据大小，使用动态大小
	int top;
	int capacity;
}ST;

//初始化
void StackInit(ST* ps);
//销毁
void StackDestroy(ST* ps);
//入栈
void StackPush(ST* ps, STDataType x);
//出栈
void StackPop(ST* ps);
//返回栈顶元素
STDataType StackTop(ST* ps);
//返回栈的元素个数
int StackSize(ST* ps);
//判断是否非空
bool StackEmpty(ST* ps);
