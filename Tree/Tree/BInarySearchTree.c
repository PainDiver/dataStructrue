#include <stdio.h>
#include <stdlib.h>

// ���������� Ʈ���� ����� ������ 
// �� ���� Ʈ���� ��Ʈ���� ������, �������� ��Ʈ���� ū ������ ������ ���´ٸ�
// ���� ���� Ž���� �� �� �������� ���� ���� ���� �� ����

typedef struct BTreeNode
{
	int data;
	struct BTreeNode* left, * right;
}BTreeNode;


BTreeNode* search(BTreeNode* node, int key)
{
	if (node == NULL)							// �ش� key���� ���ʸ���ã�� �������� ã��
		return NULL;
	if (key == node->data)
		return node;
	else if (key < node->data)
		return search(node->left, key);
	else
		return search(node->right, key);

}

BTreeNode* ForSearch(BTreeNode* node, int key)		// for������ ����
{
	while (node != NULL)
	{
		if (key == node->data)
			return node;
		else if (key < node->data)
			node = node->left;
		else
			node = node->right;
	}
	return NULL;
}

//Ž�� ��, ���Կ����� �Ͽ� BinaryTree�� ���� �㳪 �ߺ���� ����
BTreeNode* Insert_node(BTreeNode* node, int key)
{
	BTreeNode* newNode;
	if (node == NULL)
	{
		newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
		newNode->data = key;
		newNode->left = NULL;
		newNode->right = NULL;
		return newNode;
	}
	if (key < node->data)
		node->left = Insert_node(node->left, key);
	else if (key > node->data)
		node->right = Insert_node(node->right, key);
	return node;
}


//Ž���� ����, 3���� ��� ����, �ܸ���� ����, �ϳ��� ����Ʈ���� �������, �ΰ��� ����Ʈ���� ���� ���
// �ܸ����� �׳� ����� ��
// �Ѱ��� ����Ʈ���� ���� ���� ��������Ʈ���� �׳� �����ҳ���� ����忡 �̾���
// �ΰ��� ����Ʈ���� ���� ����, �������� ���ʼ���Ʈ������ ���� ū ��, �����ʼ���Ʈ������ ���� ���� �� �� �ϳ��� ��ü�� �ϸ� �ȴ�
// �׷��� ����Ʈ���� ���� ��, �׷��� ����Ž��Ʈ���� �� ���� Ž��Ʈ���� �Ǳ� ���ؼ�, �� �� ��� �� ����� ���� �ִ°� ����
BTreeNode* min_value_node(BTreeNode* node)
{
	BTreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

BTreeNode* max_value_node(BTreeNode* node)
{
	BTreeNode* current = node;
	while (current->right != NULL)
		current = current->right;
	return current;
}


BTreeNode* delete_node(BTreeNode* root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->data)
		root->left = delete_node(root->left, key);				//Ű ���� ��Ʈ���� ���� �� ���� ��ȯ
	else if (key > root->data)
		root->right = delete_node(root->right, key);			//Ű ���� ��Ʈ���� ���� �� ������ ��ȯ
	else
	{															//���� ��ġ�Ǵ°��
		if (root->left == NULL)									// �ش� ����� ������ ���캽,
		{														// �ƹ��͵� ������ ������ ���� �� ���� ��Ʈ ����
			BTreeNode* temp = root->right;
			free(root);
			return temp;										//��ȯ�Ǵ� �����ʰ��� ��ȯ���� ���������鼭 �� ���� �̾����� ��
		}
		else if (root->right == NULL)							//�ش� ����� ������
		{
			BTreeNode* temp = root->left;						//�ƹ��͵� ������ ���� ���� �� ���� ��Ʈ ����
			free(root);
			return temp;										//��ȯ�Ǵ� ���ʰ��� ��ȯ���� ���������鼭 �� ���� �̾���
		}

		BTreeNode* temp = min_value_node(root->right);			// ����������, 2���� ��� �Ѵ� �ް� �ִ� ���, ������ ���� ����,����Ʈ���� �ּҰ��� ã��
		BTreeNode* temp2 = max_value_node(root->left);			// ���ʳ��� ����Ʈ���� �ִ밪�� ���ϰ� ��
		if (abs(root->data - temp->data) < abs(root->data - temp2->data))
		{															
			root->data = temp->data;								// �� �� �� ���� ������ �� �����Ͽ� ��Ʈ�� �ٲ���
			delete_node(root->right, temp->data);					// �� ���� ������Ű�� 
		}
		else
		{
			root->data = temp2->data;
			delete_node(root->left, temp2->data);				// �ش� ���� ��Ʈ��忡 ���� ��
		}
																	// ��Ʈ�� ī���� ��带 ���� ������ ��ġ �ڸ��� ��ü�ϴ� �� ó��
	}
	return root;													// �� ��Ʈ ��ȯ���� ��ȯ���� ���� delete_node�� ����� �����鼭 �� �̾����Ե�
}


inorderB(BTreeNode* root)
{
	if (root)
	{
		inorder(root->left);
		printf("[%d]", root->data);
		inorder(root->right);
	}
}



int main()															//����Ž��Ʈ������ Ž��,����,���� ������ �ð� ���⵵�� Ʈ���� ���̿� ����
{

	BTreeNode* n1, * n2, * n3, *n4, *n5;							// ���ʼ���Ʈ���� �����ʼ���Ʈ���� ������ ������ �̰��� balanced Ʈ���� �Ѵ�.
	n1 = (BTreeNode*)malloc(sizeof(BTreeNode));						// �ּ��ǰ��� ��������Ʈ���� ����̴�. �� ��쿡��, h�� log 2 n�ε�, 15���� ��尡 ����ִٸ�, �־��� ��쿡�� 4���� ����
	n2 = (BTreeNode*)malloc(sizeof(BTreeNode));						// �־��ǰ��� �������� ġ������ �������Ʈ���� ����, h=n�� �Ǳ� ������ ����Ž���� �ð����⵵�� ����.
	n3 = (BTreeNode*)malloc(sizeof(BTreeNode));
	n4 = (BTreeNode*)malloc(sizeof(BTreeNode));						// ��, ����Ž��Ʈ������ �ּ��ǰ�� Ž��,����,���� ������ O(log n)�̴�
	n5 = (BTreeNode*)malloc(sizeof(BTreeNode));						// �־��ǰ��, O(n)�� �ȴ�
																	//�־��� ��츦 ���ֱ� ���ؼ�, �ִ��� balanced Ʈ���� �������Ѵ�.

	n5->data = 100;
	n5->left = n4;
	n4->data = 90;
	n5->right = n3;
	n3->data = 120;
	n1->data = 80;
	n2->data = 130;
	n4->left = n1;
	n4->right = NULL;
	n3->right = n2;
	n3->left = NULL;
	n1->left = NULL;
	n1->right = NULL;
	n2->left = NULL;
	n2->right = NULL;

	BTreeNode* answer = search(n5,100);

	printf("%d\n",answer?answer->data:0);

	BTreeNode* answerFor = ForSearch(n5, 120);

	printf("%d\n", answerFor?answer->data:0);

	free(n1);
	free(n2);
	free(n3);
	free(n4);
	free(n5);
	


/*
	BTreeNode* root = NULL;
	BTreeNode* tmp = NULL;

	root = Insert_node(root, 30);
	root = Insert_node(root, 20);
	root = Insert_node(root, 10);
	root = Insert_node(root, 40);
	root = Insert_node(root, 50);
	root = Insert_node(root, 60);
	root = Insert_node(root, 70);

	printf("���� Ž�� Ʈ�� ���� ��ȸ ���\n");
	inorderB(root);
	printf("\n\n");
	if (search(root, 30) != NULL)
		printf("���� Ž�� Ʈ������ 30�� �߰���\n");
	else
		printf("���� Ž�� Ʈ������ 30�� �߰߸���\n");
*/


	
	return 0;
}

