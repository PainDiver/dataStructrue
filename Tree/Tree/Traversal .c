#include <stdio.h>

typedef struct TreeNode 
{
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4,&n1,NULL };
TreeNode n3 = { 16,NULL,NULL };
TreeNode n4 = { 25,NULL,NULL };
TreeNode n5 = { 20,&n3,&n4 };
TreeNode n6 = { 15,&n2,&n5 };
TreeNode* root = &n6;

//										 n6
//										/	\
//									n2		n5
//									/\		/\
//								n1		  n3   n4
//
//������ȸ
inorder(TreeNode* root)
{
	if (root)
	{
		inorder(root->left);
		printf("[%d]", root->data);
		inorder(root->right);
	}	
}

preorder(TreeNode* root)
{
	if (root)
	{
		printf("[%d]", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

postorder(TreeNode* root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("[%d]", root->data);
	}
}

/*
int main()
{
	printf("���� ��ȸ");
	inorder(root);
	printf("\n");

	printf("���� ��ȸ");
	preorder(root);
	printf("\n");

	printf("���� ��ȸ");
	postorder(root);
	printf("\n");

	return 0;
}
*/