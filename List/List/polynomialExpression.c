
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNodeP
{
	int coef;
	int expon;
	struct ListNodeP* link;								//���׽��� ������ ����� ��� ���
}ListNodeP;

typedef struct ListTypeP
{
	int size;
	ListNodeP* head;									// ���׽ĳ�带 ����ų ��������� ���� ���
	ListNodeP* tail;
}ListTypeP;

void errorP(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}


ListTypeP* createP()
{																// �����Ҵ��ּҸ� ����� �ʱ�ȭ �ϰ� ��ȯ�ϴ� ���丮�Լ�
	ListTypeP* plist = (ListTypeP*)malloc(sizeof(ListTypeP));	
	plist->size = 0;
	plist->head = plist->tail = NULL;
	return plist;
}

void insert_lastP(ListTypeP* plist, int coef, int expon)		// ���Ḯ��Ʈ�� ������ ���� �ϳ��� �߰� ����
{
	ListNodeP* temp = (ListNodeP*)malloc(sizeof(ListNodeP));	// ��嵿������ �Ҵ�
	if (temp == NULL) errorP("�޸� �Ҵ� ����\n");				// �ش� ��忡 �����͸� �߰�
	temp->coef = coef;
	temp->expon = expon;
	temp->link = NULL;
	if (plist->tail == NULL)									// ���� ���Ḯ��Ʈ�� ����ִ°��
	{
		plist->head = plist->tail = temp;						// ���Ḯ��Ʈ�� ���,������ ��� ������ ��忡 ����
	}
	else
	{															// � ��尡 �̹� ����ִ°��,
		plist->tail->link = temp;								// ����� �������� ��� ������ ��尡 �ǹǷ�, ������ ������ ��带 ��� ������ ���� ����
		plist->tail = temp;										// ����� ��������, ��� ������ ��尡 ��
	}
	plist->size++;												// ���Ḯ��Ʈ�� �ϳ��� ��尡 �߰� �Ǿ����Ƿ� ������ +1
}

void poly_add(ListTypeP* plist1, ListTypeP* plist2, ListTypeP* plist3)
{
	ListNodeP* a = plist1->head;									// �� ���׽��� ���ؼ� ������ �Ű������� �ش��ϴ� ���׽ĳ�忡 �ִ� ���
	ListNodeP* b = plist2->head;									// 3���� ���Ḯ��Ʈ ����� ��� ��
	int sum;														// sum�� �� ���� �־��� �ӽú���

	while (a && b)													// a�� b�� ����, a�� b�� ���� tail������ ���Ե� ���̸�, ��������忡 �ٴٸ��� NULL�� �� ����
	{
		if (a->expon == b->expon)									// a�� b�� ������ ���ϰ�, ���ٸ�
		{
			sum = a->coef + b->coef;								// sum ������ a�� b�� ������ ���� ���� �ִ´�.
			if (sum != 0)											// ���� �� ���� 0�� �ƴ϶��
				insert_lastP(plist3, sum, a->expon);				// 3��° ���Ḯ��Ʈ�� �ش� ����, �ش� ������ �Ͽ� �ִ´�
			a = a->link;											// ������ a�� b�� ���� ���� �̵�
			b = b->link;
		}
		else if (a->expon > b->expon)								// a�� b�� ������ ���ϰ� a�� �� ũ�ٸ�
		{
			insert_lastP(plist3, a->coef, a->expon);				// a�� ������ ����� �״�� ����
			a = a->link;											// �׸��� a�� ���� ���� �̵�
		}
		else
		{
			insert_lastP(plist3, b->coef, b->expon);				// ���� ������, b�� �� ū���
			b = b->link;
		}
	}
	for (; a != NULL; a = a->link)									// �� ����Ʈ �� �ϳ��� ���� ������ while���� ������, �� ���� ��, �� �̻� ��ġ�� ������ ���ٴ� �ǹ� (������� �ִٴ� �����Ͽ�)
		insert_lastP(plist3, a->coef, a->expon);					// �׷��Ƿ� ���� ��嵥���͵��� ����Ʈ3�� �־��ش�.
	for (; b != NULL; b = b->link)
		insert_lastP(plist3, b->coef, b->expon);
}

void poly_print(ListTypeP* plist)
{
	ListNodeP* p = plist->head;										// ����Ʈ����� �޾Ƽ�
	
	printf("Polynomial =");
	for (; p; p = p->link)											// ������ ��� ���� ���
	{
		if(p->expon !=0)											
			printf("%dx^%d+ ",p->coef, p->expon);					
		else
			printf("%d", p->coef);
	}
	printf("\n");
}

/*
int main(void)
{
	ListTypeP* list1, * list2, * list3;

	list1 = createP();
	list2 = createP();
	list3 = createP();

	insert_lastP(list1, 3, 12);
	insert_lastP(list1, 2, 8);
	insert_lastP(list1, 1, 0);

	insert_lastP(list2, 8, 12);
	insert_lastP(list2, -3, 10);
	insert_lastP(list2, 10, 6);
											//���⼭ ���� poly_add�� ���׽ĵ��� ��� �̹� ���������� �Ǿ��־�� ��
	poly_print(list1);
	poly_print(list2);

	poly_add(list1, list2, list3);
	poly_print(list3);

	free(list1);
	free(list2);
	free(list3);
}
*/