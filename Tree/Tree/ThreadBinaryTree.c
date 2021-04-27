#include <stdio.h>
// each node points the next node to be refered
// for all nodes which has null in right node will points that.

typedef struct TTreeNode
{
	int data;
	struct TreeNode* left, * right;
	int is_thread;		//������ ��尡 ������������ �ڽĳ������ �����Ͽ� �ܸ�������� ��ܸ�������� Ȯ��
}TTreeNode;				// ���� NULL�̿����ϴ� �����ʰ��� ���� �ļ��ڷ� ����� ���� ����������


TTreeNode* find_successor(TTreeNode* p)		//���� �ļ��� ã��( �����ļ��ڴ� ����ǥ�⿡�� ������ �Ͼ ���)
{
	TTreeNode* q = p->right; 
	if (q == NULL || (p->is_thread == 1))
		return q;
	while (q->left != NULL)
		q = q->left;
	return q;
}

void thread_inorder(TTreeNode* t)
{
	TTreeNode* q;
	q = t;
	while (q->left)
		q = q->left;
	do
	{
		printf("%d", q->data);
		q = find_successor(q);
	} while (q);
}

int main()
{
	TTreeNode a1 = { 1,NULL,NULL,1 };
	TTreeNode a2 = { 2,NULL,NULL,0 };
	TTreeNode a3 = { 3,NULL,NULL,1 };
	TTreeNode a4 = { 4,NULL,NULL,1 };
	TTreeNode a5 = { 5,&a1,NULL,1 };
	TTreeNode a6 = { 6,&a3,&a2,0 };
	TTreeNode a7 = { 7,&a5,&a4,0 };
	TTreeNode a8 = { 8,&a7,&a6,0 };
	
	a1.right = &a5;
	a5.right = &a7;
	a4.right = &a8;
	a3.right = &a6;

	thread_inorder(&a8);

	return 0;
}