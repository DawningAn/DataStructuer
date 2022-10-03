# define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
//带有哨兵头节点的 双向链表
typedef int LTDataType;

typedef struct ListNode {
	LTDataType data;
	struct ListNode* prev;
	struct ListNode* next;
}ListNode;
//打印链表
void ListPrint(ListNode* phead);
//初始化链表
ListNode* ListInit();
//销毁链表
void ListDestory(ListNode* phead);

//头插
void ListPushFront(ListNode* phead, LTDataType x);
//尾插
void ListPushBack(ListNode* phead, LTDataType x);
//头删
void ListPopFront(ListNode* phead);
//尾删
void ListPopBack(ListNode* phead);
//查找
ListNode* ListFind(ListNode* phead, LTDataType x);
//插入
void ListInsert(ListNode* phead, LTDataType tmp, LTDataType x);
//删除
void ListEraser(ListNode* phead, LTDataType x);
//判断链表是否为空
int isEmpyt(ListNode* phead);
//链表计数
int ListSize(ListNode* phead);
