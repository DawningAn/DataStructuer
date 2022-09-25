# define _CRT_SECURE_NO_WARNINGS 1
#include "SeqList.h"

//ʵ��˳����ʼ��
void SeqListInit(SL* ps) {
	ps->a = NULL;
	ps->size = ps->capacity = 0;
}

//��ӡ����
void SeqListPrint(SL* ps) {
	for (int i = 0; i < ps->size; i++) {
		printf("%d ", ps->a[i]);
	}

}
//ʵ��β��
//����Ҫ��������
void SeqListPushBack(SL* ps, SLDataType x) {
	if (ps->size == ps->capacity) {
		//���û�пռ䣬��ôҪ��ʼ��
		//��������ռ�����Ҫ����
		//printf("��ǰ�ռ�������");  //��ʱ��Ҫ����
		int newcapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;  //����һ��ʼ��û�пռ�����
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newcapacity * sizeof(SLDataType));

		if (tmp == NULL) {
			printf("realloc fail\n");
			exit(-1);
		}
		//������ٿռ�ɹ����ͽ���ʱ�ռ丳��ԭ����ָ��
		ps->a = tmp;
		ps->capacity = newcapacity;

	}
	ps->a[ps->size] = x;
	ps->size++;
}

void SeqListPushFront(SL* ps, SLDataType x);

void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);