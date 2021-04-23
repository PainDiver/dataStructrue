#include <stdio.h>
#include <malloc.h>

typedef int elementS;

typedef struct StackNode
{
	elementS data;
	struct StackNode* link;
}QueueNode;


typedef struct
{
	QueueNode* top;					//�����̹Ƿ� top��带 ����Ű�� top������
}LinkedStackType;

void initS(LinkedStackType* s)
{
	s->top = NULL;
}

int is_emptyS(LinkedStackType* s)
{
	return (s->top == NULL);
}

int is_fullS(LinkedStackType* s)
{
	return 0;
}

void pushS(LinkedStackType* s, elementS item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));		// ���ó�带 �������ش�
	temp->data = item;												// ���ó���� �����͸� ���� �� ��,
	temp->link = s->top;											// �� ��尡  �ٷξƷ���带 ����Ű�� �Ѵ�.
	s->top = temp;													// top�����ʹ� ���� �ֻ����� �ִ� top��带 ����Ų��.
}

void print_stack(LinkedStackType* s)
{
	for (QueueNode* p = s->top; p != NULL; p = p->link)			// top���� �ϳ��� ����, �ϳ��� ���������� �������鼭 ����ϰ� ��
		printf("%d->", p->data);
	printf("NULL\n");
}

elementS popS(LinkedStackType* s)
{
	if (is_emptyS(s))
	{
		fprintf(stderr, "���� ��");
		exit(1);
	}
	else
	{
		QueueNode* temp = s->top;								// ž��带 �ӽ÷� �����Ͽ�
		int data = temp->data;									// �ش� ����� �����͸� ���ְ�
		s->top = s->top->link;									// top�����͸� ���� top�� �����ҰŴϱ� top�ؿ� �ִ� �����ͷ� ����
		free(temp);												// top�� ����
		return data;
	}
}

/*
int main(void)
{
	LinkedStackType s;
	initS(&s);
	pushS(&s, 1);
	print_stack(&s);
	pushS(&s, 2);
	print_stack(&s);
	pushS(&s, 3);
	print_stack(&s);

	popS(&s);
	print_stack(&s);
	popS(&s);
	print_stack(&s);
	popS(&s);
	print_stack(&s);
	return 0;
}
*/