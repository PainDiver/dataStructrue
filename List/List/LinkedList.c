
#include <stdio.h>
#include <stdlib.h>

typedef int elementL;

typedef struct ListNodeL
{
	elementL data;
	struct ListNodeL* link;				//���Ḯ��Ʈ�� ���� ���� ���� ����Ǿ���ϹǷ� ��������͸� ����

}ListNodeL;

ListNodeL* insert_firstL(ListNodeL* head, int value)
{
	ListNodeL* p = (ListNodeL*)malloc(sizeof(ListNodeL));		// �� �� ��带 �����ϴ� ����
	p->data = value;											// p�� ��� �����Ҵ��� �ϰ� �����͸� ���� �� ��ȯ ����
	p->link = head;												// p�� �������link�� ������ ��带 ����Ű��
	head = p;													// head�� ���� ������ ��尡 �ȴ�.
	return head;
}

ListNodeL* insertL(ListNodeL* head, ListNodeL* pre, elementL value)
{																//pre�� �����ʿ� ��� �߰�
	ListNodeL* p = (ListNodeL*)malloc(sizeof(ListNodeL));		// p�� ����
	p->data = value;											// p�� �����͸� ���
	p->link = pre->link;										// pre�� ���� ��带 p�� link�� �����Ͽ�, ���� �־���
	pre->link = p;												// pre�� ���� ��带 ��� ������ p�� ����
	return head;
}


ListNodeL* delete_fristL(ListNodeL* head)
{
	ListNodeL* removed;										// head���� ���Ḯ��Ʈ�� ������
	if (head == NULL) return NULL;							// head�� NULL�̶�� ���Ḯ��Ʈ�� �ƹ���嵵 ���� ���̹Ƿ� ��ȯ
	removed = head;											// �����带 ��� ������ ��ü
	head = removed->link;									// head�� ���� removed->link�� ����Ŵ, �� �Ǿճ���� ������带 ����Ŵ
	free(removed);											// removed�� �����Ҵ�� �Ǿ��ּҸ� ����Ű�Ƿ� �̸� ������
	return head;											
}

ListNodeL* deleteL(ListNodeL* head, ListNodeL* pre)		
{															//head���� ���Ḯ��Ʈ ����
	ListNodeL* removed;										// ���ﰴü ����
	removed = pre->link;									// ������� pre�� ���� ���
	pre->link = removed->link;								// pre�� �������� ���� �������� �������
	free(removed);											// �����带 ����
	return head;											
}

void print_listL(ListNodeL* head)
{
	for (ListNodeL* p = head; p != NULL; p = p->link)		//p�� NULL�� �ƴҶ����� p = p->link�� ��ȸ�ϸ鼭 ��� 
		printf("%d->", p->data);
	printf("NULL\n");
}

ListNodeL* search_listL(ListNodeL* head, elementL x)	
{	
	ListNodeL* p = head;								// ã�� �����͸� ������ �ִ� ������ �˻��Ѵ�.

	while (p != NULL)									// ����Ʈ�� ��ȸ��Ų��.
	{
		if (p->data == x)								// ��忡�� Ž�������͸� ã�� ��, �ش� ����ּҸ� ��ȯ
			return p;
		p = p->link;
	}
	return NULL;										//������ NULL
}

ListNodeL* concat_listL(ListNodeL* head1, ListNodeL* head2)
{														//����Ʈ�� �̾��ִ� �Լ�, ù ����Ʈ�� �ڷ� �ι�° ����Ʈ�� ���� ��
	if (head1 == NULL)									// ����Ʈ1�� ������� ����Ʈ2��ȯ
		return head2;
	else if (head2 == NULL)								// ����Ʈ2�� ������� ����Ʈ1 ��ȯ
		return head1;
	else												// ����Ʈ 12 ��� �������
	{
		ListNodeL* p;									// �� ��带 ����� ����Ʈ 1 ����
		p = head1;										 
		while (p->link != NULL)							// ����Ʈ�� ������ ��
			p = p->link;
		p->link = head2;								// ����Ʈ�� ���� ����Ʈ2�� �̾���
		return head1;
	}

}

ListNodeL* reverse(ListNodeL* head)
{
	ListNodeL* p,* q,* r;								//����Ʈ�� �������� ����� �Լ�
	
	p = head;											//p�� ��ȸ���
	q = NULL;											//q�� �̾��ִ� ���
	while (p != NULL)									//r�� �̾������� ���
	{
		r = q;											// r�� q�� �̵�
		q = p;											// q�� p�� �̵�
		p = p->link;									// p�� �������� �̵�
		q->link = r;									// q�� ������� r�� �̾��ְ� ��
	}
	return q;											// q�� �����ϴ� head��� ��ȯ
}

/*
int main()
{
	ListNodeL* head = NULL;
	ListNodeL* search = NULL;
	for (int i = 0; i < 5; i++)
	{
		head = insert_firstL(head, i);
		print_listL(head);
		head = reverse(head);
		search = search_listL(head, 2);
		if(search!=NULL)
			printf("%d\n", search->data);
		print_listL(head);
	}
	for (int i = 0; i < 5; i++)
	{
		head = delete_fristL(head);
		print_listL(head);
	}
	return 0;

}
*/