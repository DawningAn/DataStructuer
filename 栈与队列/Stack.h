# define _CRT_SECURE_NO_WARNINGS 1
#pragma once  //��ֹͷ�ļ����ظ�����
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>
//ջ��Ȼ����������ʵ�֣�Ҳ����������˫�����������ʵ��

//ѡ��������ʵ��ջ��CPU�������и��ߣ�
typedef int STDataType;
typedef struct Stack {
	STDataType* a;
	//��ʹ�þ�̬�����ݴ�С��ʹ�ö�̬��С
	int top;
	int capacity;
}ST;

//��ʼ��
void StackInit(ST* ps);
//����
void StackDestroy(ST* ps);
//��ջ
void StackPush(ST* ps, STDataType x);
//��ջ
void StackPop(ST* ps);
//����ջ��Ԫ��
STDataType StackTop(ST* ps);
//����ջ��Ԫ�ظ���
int StackSize(ST* ps);
//�ж��Ƿ�ǿ�
bool StackEmpty(ST* ps);
