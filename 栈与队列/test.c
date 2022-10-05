# define _CRT_SECURE_NO_WARNINGS 1
#include "Stack.h"
#include "Queue.h"
void TestStack() {
	ST S;
	StackInit(&S);
	StackPush(&S, 10);
	StackPush(&S, 20);
	StackPush(&S, 30);
	StackPush(&S, 40);
	StackPush(&S, 50);

	while (!StackEmpty(&S)) {
		printf("%d ", StackTop(&S));
		StackPop(&S);
	}

	printf("\n");
	StackDestroy(&S);

}

void TestQueue() {
	//���� ��β������ͷ��
	//�����˵�����
	Queue Q;
	QueueInit(&Q);

	QueuePush(&Q, 10);
	QueuePush(&Q, 20);
	QueuePush(&Q, 30);
	QueuePush(&Q, 40);
	QueuePush(&Q, 50);

	while (!QueueEmpty(&Q)) {
		printf("%d ", QueueFront(&Q));
		QueuePop(&Q);
	}
	
}
int main() {
	//TestStack();
	TestQueue();
	return 0;
}