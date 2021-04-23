
#include <stdio.h>
#include <stdlib.h>

#define MAX_LIST_SIZE 100

typedef int elementA;

typedef struct ArrayListTypeA 
{
	elementA array[MAX_LIST_SIZE];			// �迭�� ũ�Ⱑ �������ִ� ����Ʈ��
	int size;
}ArrayListTypeA;

void errorA(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void initA(ArrayListTypeA* L)
{
	L->size = 0;					// �ʱ�ȭ �� ������� 0
}

int is_emptyA(ArrayListTypeA* L)
{
	return L->size == 0;			// ������� Ȯ���ϴ� �Լ�
}

int is_fullA(ArrayListTypeA* L)
{
	return L->size == MAX_LIST_SIZE;		//�� á���� Ȯ���ϴ� �Լ�
}

elementA get_entryA(ArrayListTypeA* L, int pos)
{
	if (pos < 0 || pos >= L->size)				//�ش� �ε����� ��Ҹ� ��ȯ
		errorA("��ġ ����");
	return L->array[pos];
}

void print_listA(ArrayListTypeA* L)
{
	int i;
	for (i = 0; i < L->size; i++)				// ��� ��ҵ��� ���
		printf("%d->", L->array[i]);
	printf("\n");
}

void insert_lastA(ArrayListTypeA* L, elementA item)
{
	if (L->size >= MAX_LIST_SIZE)				// ����� �ִ�ġ�� �ƴ϶��,
	{
		errorA("����Ʈ �����÷ο�");				// ������ ��Ҹ� ����
	}
	L->array[L->size++] = item;					// ����� �ش��ϴ� �κп� ��Ҹ� �ְ� ���ؾ� �� �ε���0�� ������ ������1�� �ߴ�,
}												// ������ �ְԵǸ� �ε���1�� �ְ�, ��� ������ 2���� �Ǵ°��� 

void insertA(ArrayListTypeA* L, int pos, elementA item)
{
	if (!is_fullA(L) && (pos >= 0) && (pos <= L->size))	// ����Ʈ�� �� ���� �ʰ�, �ε��� ���� ������ ���� �ȿ� �ִٸ�
	{
		for (int i = (L->size - 1); i >= pos; i--)		//������ ��Һ��� pos���� ��ĭ�� �ڷ� �ű��.		
			L->array[i + 1] = L->array[i];				
		L->array[pos] = item;							// ���������� pos�� ���� ����
		L->size++;										// ������ +1
	}
}

elementA deleteA(ArrayListTypeA* L, int pos)
{
	elementA item;
	if (pos < 0 || pos >= L->size)
		errorA("��ġ ����");
	item = L->array[pos];								// ��������� ����
	for (int i = pos; i < (L->size - 1); i++)			// pos���� size-1���� ��ĭ�� ������ ��ܿ´�. 
		L->array[i] = L->array[i + 1];
	L->size--;
	return item;
}

/*
int main()
{
	ArrayListTypeA list;
	
	init(&list);
	insert(&list, 0, 10);
	print_list(&list);
	insert(&list, 0, 20);
	print_list(&list);
	insert(&list, 0, 30);
	print_list(&list);
	insert_last(&list, 40);
	insert(&list, 2, 3);
	print_list(&list);

	delete(&list, 0);
	print_list(&list);
	return 0;

}
*/