#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;					// ���ÿ� ���� �ڷ����� �׻� �ٲ� �� �����Ƿ� typedef��

typedef struct StackType
{
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s)			// �ʱ�ȭ�� top�� -1�� ����鼭 ����
{
	s->top = -1;
}


int is_empty(StackType* s)
{
	return (s->top == -1);					// ��Ұ� ���� ���� -1�� ����Ŵ
}

int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));	// ��Ұ� ���� �� ���� MAX-1, top�� MAX�� �ε��������� �Ѿ
}

void push(StackType* s,element item)
{
	if (is_full(s))
	{												// ���� ��ȭ ����ó�� ��,
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;						// top�� 1 �ø��� ���ÿ� ���� �־� ��
}

element pop(StackType* s)
{
	if (is_empty(s))								//��Ұ� ����� �� ����ó��,
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];					// ���ÿ� top ���� ���� �� -1 ����
}

/*
int main(void)
{
	
					Stack Stack
	StackType s;

	init_stack(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 3);
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	printf("%d\n", pop(&s));
	
	

	
	
					Dynamic Stack
	StackType* s;

	s = (StackType*)malloc(sizeof(StackType));
	init_stack(s);
	push(s, 1);
	push(s, 2);
	push(s, 3);
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));
	printf("%d\n", pop(s));

	return 0;
	
}
*/