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
	printf("\n");

}
//����˳���
void SeqListDestory(SL* ps) {
	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}
//���˳�������
void Check_capacity(SL* ps) {
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
}
//ʵ��β��
void SeqListPushBack(SL* ps, SLDataType x) {

	Check_capacity(ps);
	
	ps->a[ps->size] = x;
	ps->size++;
}
//ʵ��ͷ��
void SeqListPushFront(SL* ps, SLDataType x) {

	Check_capacity(ps);
	//��β����ʶŲ������
	int end = ps->size - 1;
	while (end >= 0) {
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}
//ʵ��βɾ
void SeqListPopBack(SL* ps) {
	if (ps->size == 0) {
		printf("˳�����Ԫ�أ�\n");
		return;
	}

	ps->size--;
}
//ʵ��ͷɾ
void SeqListPopFront(SL* ps) {
	assert(ps->size > 0);
	int begin = 1;
	if (ps->size != 0) {
		while (begin < ps->size) {
			ps->a[begin - 1] = ps->a[begin];
			begin++;
		}
		ps->size--;
	}
}
//����ֵ��λ�ã������±�,�Ҳ�������-1
int SeqListFind(SL* ps, SLDataType x) {
	for (int i = 0; i < ps->size; i++) {
		if (ps->a[i] == x) {
			return i;
		}
	}
	return -1;
}
// ��ĳ��λ�ã�pos������Ԫ��x
void SeqListInsert(SL* ps, int pos, SLDataType x) {
	assert(pos < ps->size);
	int end = ps->size - 1;
	while (end >= pos) {
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}
//ɾ��posλ�õ�����
void SeqListEraser(SL* ps, int pos) {
	assert(pos < ps->size);
	int tmp = pos;
	while (tmp < ps->size - 1) {
		ps->a[tmp] = ps->a[tmp + 1];
		tmp++;
	}
	ps->size--;
}