#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct TreeNodeH 
{
	int weight;
	char ch;
	struct TreeNodeH* left;
	struct TreeNodeH* right;
}TreeNodeH;

typedef struct 
{
	TreeNodeH* ptree;
	char ch;
	int key;
}elementH;

typedef struct 
{
	elementH heap[MAX_ELEMENT];
	int heap_size;
}HeapTypeH;

HeapTypeH* createH()
{
	return (HeapTypeH*)malloc(sizeof(HeapTypeH));
}

void initH(HeapTypeH* h)
{
	h->heap_size = 0;
}

void insert_min_heap(HeapTypeH* h, elementH item)
{
	int i;
	i = ++(h->heap_size);
	while ((i != 1) && (item.key < h->heap[i / 2].key) )
	{
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

elementH delete_min_heap(HeapTypeH* h)
{
	int parent, child;
	elementH item, temp;
	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;
	while (child <= h->heap_size)
	{
		if ((child > h->heap_size) && (h->heap[child].key) > h->heap[child + 1].key)
			child++;
		if (temp.key < h->heap[child].key)
			break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

TreeNodeH* make_tree(TreeNodeH* left,TreeNodeH* right)
{
	TreeNodeH* node = (TreeNodeH*)malloc(sizeof(TreeNodeH));
	node->left = left;
	node->right = right;
	return node;
}

void destroy_tree(TreeNodeH* root)
{
	if (root == NULL)
		return;
	destroy_tree(root->left);
	destroy_tree(root->right);
	free(root);
}

int is_leaf(TreeNodeH* root)
{
	return !(root->left) && !(root->right);
}

void print_array(int codes[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d", codes[i]);
	printf("\n");
}

void print_codes(TreeNodeH* root, int codes[], int top)
{
	if (root->left)
	{
		codes[top] = 1;
		print_codes(root->left, codes, top + 1);
	}

	if (root->right)
	{
		codes[top] = 0;
		print_codes(root->right, codes, top + 1);
	}

	if (is_leaf(root))
	{
		printf("%c:", root->ch);
		print_array(codes, top);
	}

}

void huffman_tree(int freq[], char ch_list[], int n)
{
	int i;
	TreeNodeH* node, * x;
	HeapTypeH* heap;
	elementH e, e1, e2;
	int codes[100];
	int top = 0;
	heap = createH();
	initH(heap);
	for (i = 0; i < n; i++)
	{
		node = make_tree(NULL, NULL);			//���ڳ�带 ����� �ּ�ť�� �ִ� ����
		e.ch = node->ch = ch_list[i];
		e.key = node->weight = freq[i];
		e.ptree = node;
		insert_min_heap(heap, e);
	}

	for (i = 1; i < n; i++)
	{
		e1 = delete_min_heap(heap);
		e2 = delete_min_heap(heap);
		x = make_tree(e1.ptree, e2.ptree);
		e.key = x->weight = e1.key + e2.key;
		e.ptree = x;
		printf("%d+%d->%d\n", e1.key, e2.key, e.key);
		insert_min_heap(heap, e);
	}
	e = delete_min_heap(heap);
	print_codes(e.ptree, codes, top);
	destroy_tree(e.ptree);
	free(heap);

}

int main(void)
{
	char ch_list[] = { 's','i','n','t','e' };
	int freq[] = { 4,6,8,12,15 };
	huffman_tree(freq, ch_list, 5);
	return 0;
}

//�ؽ�Ʈ�� e,t,n,i,s 5�� ���ڷθ� �̷�����ٰ� �����Ѵ�.
// �� ���ڰ� ���� ���� ������ 45, 5���� ���ڸ� ǥ���ϱ� ���ؼ� (000,001,010,011,100) 3��Ʈ�� �ʿ���
// �� 45���� ���� * 3��Ʈ = 145��Ʈ�� �ʿ�

//���� ���ֳ����� �ڵ带 2��Ʈ�� ���̰�, ���־ȳ����°�� 3��Ʈ�� ǥ���Ѵٸ� �ʿ��Ʈ�� ���� �� �ִ�.
//ex) e t n�� ���־��̴� ���ڶ��(00 01 10), i s�� ���� ������ �ʴ´ٸ� (110 111) ��Ʈ�� ���� �� ����, �ٸ��ڵ��� ���κΰ� ���ԵǸ�ȵ�
// ������� 00���� �����ϴ� �༮�� �ִٸ� 001�� �ȵ�, 11�� �ִٸ� 110�̳� 111�� �ȵ�

//���� 01000010 �̶� �ڵ尡 �ִٸ�, ��� �������� ���ؾ��Ѵ�. 01 or 010 �㳪 ���⼱ 010�� �����Ƿ� 01
//���� �ڵ�� 00 or 000, 000�� �����Ƿ� 00��

//����:
/*
	1. ��� ���ڸ� ���� �󵵼��� ���� ����,
	2. ���� �󵵰� ���� ���� 2���� �ּ� ���� �̿��ؼ�, ����Ʈ���� �����, ��Ʈ�� �� ����� ��
	3. ������ �ܸ���� 2���� �����ϰ� ��Ʈ ��带 ����
	4. ��Ͽ� 1���� ���� �� ���� 2-3�� �ݺ�
	5. ���� �ڽ��� 1, ������ �ڽ��� 0�� ��ũ

	��������� �ܾ��� �ڵ�� �� Ʈ���� ���ؼ� �������� �ȴ�.
	
	�������) s�� ��Ʈ�� ���� �������� 1,1,1�̶� �ڵ带 ��� ��(111)
			 i�� ��Ʈ�� ���� �������� 1,1,0�̶� �ڵ带 ��Ե� (110)

					   45
					/	  \
			      /	        \
		      18(1)			  \
		    /	    \	        \
		10(1)	     \		    27(0)
		/    \        \	        /	  \
	4(s)(1)  6(i)(0) 8(n)(0) 12(t)(1) 15(e)(0)


	���� ����ܰ�:
	1. �󵵼��� ���� �켱���� ť ���� (s,i,n,t,e)������ �ּ�ť�� ���̰� ��
	2. �켱������ ���� 2���� ���� �� ����Ʈ�� ����, ������ 2���� ��ȯ�޾� �����ϴܺκ�Ʈ���� �����. ���� �ּ�ť�� n,t,e�� ���Ե�
	3. ������ 2���� ��� �� ���� ��(10)�� �ش��ϴ� �θ��带, ���� �ּ�ť�� ��������
	
	�ּ�ť�� ������� �� ���� 2�� 3�� ��� �ݺ�
	������ ������,�����ڽĿ� ���� 0,1 ��ũ
*/



