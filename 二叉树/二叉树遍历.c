# define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode {
	struct BinaryTreeNode* left;  
	struct BinaryTreeNode* right;
	BTDataType val;
}BTNode;

//���ֱ���
//ǰ��
void PrevOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->val);  //��ӡ����ֵ
	PrevOrder(root->left);  //�ȱ�������
	PrevOrder(root->right);  //���������
}
//����
void InOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}
//����
void PostOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->val);
}
int main() {
	//����ǰ�����
	//�����ڵ�
	BTNode* A = (BTNode*)malloc(sizeof(BTNode));
	A->val = 'A';
	A->left = NULL;
	A->right = NULL;
	BTNode* B = (BTNode*)malloc(sizeof(BTNode)); 
	B->val = 'B';
	B->left = NULL;
	B->right = NULL;
	BTNode* C = (BTNode*)malloc(sizeof(BTNode));
	C->val = 'C';
	C->left = NULL;
	C->right = NULL;
	BTNode* D = (BTNode*)malloc(sizeof(BTNode));
	D->val = 'D';
	D->left = NULL;
	D->right = NULL;
	BTNode* E = (BTNode*)malloc(sizeof(BTNode));
	E->val = 'E';
	E->left = NULL;
	E->right = NULL;

	//����5���ڵ��������
	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	//����ǰ�����
	PrevOrder(A);
	printf("\n");
	//�����������
	InOrder(A);
	printf("\n");
	//���Ժ������
	PostOrder(A);
	printf("\n");

	return 0;
}