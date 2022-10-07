# define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
typedef char BTDataType;
typedef struct BinaryTreeNode {
	struct BinaryTreeNode* left;  
	struct BinaryTreeNode* right;
	BTDataType val;
}BTNode;

//三种遍历
//前序
void PrevOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%c ", root->val);  //打印根的值
	PrevOrder(root->left);  //先遍历左树
	PrevOrder(root->right);  //后遍历右树
}
//中序
void InOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	InOrder(root->left);
	printf("%c ", root->val);
	InOrder(root->right);
}
//后序
void PostOrder(BTNode* root) {
	if (root == NULL) {
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%c ", root->val);
}
int main() {
	//测试前序遍历
	//创建节点
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

	//将这5个节点进行链接
	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;
	//测试前序遍历
	PrevOrder(A);
	printf("\n");
	//测试中序遍历
	InOrder(A);
	printf("\n");
	//测试后序遍历
	PostOrder(A);
	printf("\n");

	return 0;
}