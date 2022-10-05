#include "Stack.h"

//��ʼ��
void StackInit(ST* ps) {
	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL) {
		printf("realloc fail\n");
		exit(-1);
	} 
	
	//��ʼ��topջ��Ϊ0����topָ�����ջ������һ��Ԫ��
	//��ʼ��topջ��Ϊ-1����topָ�����ջ����Ԫ��
	ps->top = 0;
	ps->capacity = 2;
}
//����
void StackDestroy(ST* ps) {
	assert(ps);
	free(ps->a);
	ps -> a = NULL;
	ps->top = ps->capacity = 0;
}
//��ջ
void StackPush(ST* ps, STDataType x) {
	assert(ps);
	//Ҫ��������
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
//��ջ
void StackPop(ST* ps) {
	assert(ps);
	assert(ps->top > 0);  //ջ�ǿղſ���ɾ��
	ps->top--;
}
//����ջ��Ԫ��
STDataType StackTop(ST* ps) {
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top -1];
}
//����ջ��Ԫ�ظ���
int StackSize(ST* ps) {
	assert(ps);

	return ps->top;
}
//�ж��Ƿ�ǿ�
bool StackEmpty(ST* ps) {
	assert(ps);
	return ps->top == 0;
}