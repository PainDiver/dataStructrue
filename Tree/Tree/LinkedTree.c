#include <stdio.h>

typedef struct TreeNode 
{
	int data;
	struct TreeNode* left, * right;
}TreeNode;

//			n1
//	 	 /		\
//		n2		n3
// ��ȸ �� �׻�, R���� L�̸����;ߵ�
// VLR ������ȸ, LVR ������ȸ ,LRV ������ȸ �� ����

/*
		  1
		/	\
	  2		 3
	/	\	   \
   4	 5		8
		  \	     \
		   6	   9
		  /
		7

������ȸ		
1	(2,4,5,6,7)			(3,8,9)				�ֻ�����			
	2	 4 (5,6,7)		3	x (8,9)			��ȣ ������ Ǯ��� ����
			5 6 7				8,9			���� ��ȣ ���� �κ� �а� ������ ������ ��
124567389

������ȸ
(2,4,5,6,7)					1			(3,8,9)
	4	2	(5,6,7)						x	3	8
			x	5	6								9
						7

������ȸ
(�������)		(�������)	��Ʈ���
=> (2,4,5,6,7)	(3,8,9)		1


*/


/*
int main()
{
	//�⺻ ����
	TreeNode* n1, * n2, * n3;
	n1 = (TreeNode*)malloc(sizeof(TreeNode));
	n2 = (TreeNode*)malloc(sizeof(TreeNode));
	n3 = (TreeNode*)malloc(sizeof(TreeNode));

	n1->data = 10;
	n1->left = n2;
	n1->right = n3;
	n2->data = 20;
	n2->left = NULL;
	n2->right = NULL;
	n3->data = 30;
	n3->left = NULL;
	n3->right = NULL;
	free(n1);
	free(n2);
	free(n3);
	
	return 0;
}
*/