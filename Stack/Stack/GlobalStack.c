#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int element;					// ���ÿ� ���� �ڷ����� �׻� �ٲ� �� �����Ƿ� typedef��

element stack[MAX_STACK_SIZE];			// ���� ���� �ڷ����迭�� ������, ũ�������� ����
int top = -1;							// top�� �׻� -1�� ������, �׷��� 0��° �ε������� ���ʴ�� ���� ��

int is_emptyGlob()		
{
	return (top == -1);					// ��Ұ� ���� ���� -1�� ����Ŵ
}

int is_fullGlob()
{
	return (top == (MAX_STACK_SIZE - 1));	// ��Ұ� ���� �� ���� MAX-1, top�� MAX�� �ε��������� �Ѿ
}

void pushGlob(element item)
{
	if (is_fullGlob())
	{												// ���� ��ȭ ����ó�� ��,
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else stack[++top] = item;						// top�� 1 �ø��� ���ÿ� ���� �־� ��
}

element popGlob()
{
	if (is_emptyGlob())								//��Ұ� ����� �� ����ó��,
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return stack[top--];					// ���ÿ� top ���� ���� �� -1 ����
}

/*
int main(void)
{
	push(1);
	push(2);
	push(3);
	printf("%d\n", pop());
	printf("%d\n", pop());
	printf("%d\n", pop());
	return 0;
}
*/