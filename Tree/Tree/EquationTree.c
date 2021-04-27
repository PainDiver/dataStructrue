//prefix order ���

#include <stdio.h>

typedef struct TreeNode
{
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode pn1 = { 1,NULL,NULL };
TreeNode pn2 = { 4, NULL,NULL };
TreeNode pn3 = { '*',&pn1,&pn2 };
TreeNode pn4 = { 16,NULL,NULL };
TreeNode pn5 = { 25,NULL,NULL };
TreeNode pn6 = { '+',&pn4,&pn5 };
TreeNode pn7 = { '+',&pn3,&pn6 };
TreeNode* exp = &pn7;

int evaluate(TreeNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return root->data;
	else
	{
		int op1 = evaluate(root->left);
		int op2 = evaluate(root->right);
		printf("%d %c %d�� ����մϴ�.\n", op1, root->data, op2);
		switch (root->data)
		{
			case '+': return op1 + op2;
			case '-': return op1 - op2;
			case '*': return op1 * op2;
			case '/': return op1 / op2;
		}
	}
	return 0;
}

/*
int main()
{
	printf("������ ���� %d�Դϴ�. \n", evaluate(exp));
	return 0;
}
*/