#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef char elementITP;					// ���ÿ� ���� �ڷ����� �׻� �ٲ� �� �����Ƿ� typedef��

typedef struct StackTypeITP
{
	elementITP data[MAX_STACK_SIZE];
	int top;
}StackTypeITP;

void init_stackITP(StackTypeITP* s)			// �ʱ�ȭ�� top�� -1�� ����鼭 ����
{
	s->top = -1;
}


int is_emptyITP(StackTypeITP* s)
{
	return (s->top == -1);					// ��Ұ� ���� ���� -1�� ����Ŵ
}

int is_fullITP(StackTypeITP* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));	// ��Ұ� ���� �� ���� MAX-1, top�� MAX�� �ε��������� �Ѿ
}

void pushITP(StackTypeITP* s, elementITP item)
{
	if (is_fullITP(s))
	{												// ���� ��ȭ ����ó�� ��,
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;						// top�� 1 �ø��� ���ÿ� ���� �־� ��
}

elementITP peekITP(StackTypeITP* s)
{
	return s->data[s->top];
}


elementITP popITP(StackTypeITP* s)
{
	if (is_emptyITP(s))								//��Ұ� ����� �� ����ó��,
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];					// ���ÿ� top ���� ���� �� -1 ����
}

int prec(char op)						//�������� �켱������ ���ϴ� �Լ�
{
	switch (op)
	{
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}


void infix_to_postfix(char exp[])
{
	int i = 0;						 
	char ch, top_op;				// ch�� ���ڸ� ����, top_op�� ����� ������ �����ö� ���� ���� 
	int len = strlen(exp);			 
	StackTypeITP s;					// ���� �ʱ�ȭ

	init_stackITP(&s);
	for (i = 0; i < len; i++)
	{
		ch = exp[i];				// ���� �ѱ��ڸ� �޾ƿ�
		switch (ch)
		{
			case '+': case '-' : case '*': case '/':		// �� ���ڰ� ������ �� ��,
				while (!is_emptyITP(&s) && (prec(ch) <= prec(peekITP(&s))))	// ������ �����ʾҰ�, ��ݵ��� �����ڰ� �������� �ͺ��� ���� ������ ���ٸ�. �������� ������ ���
				{
					printf("%c", popITP(&s));	// ������ ������
				}
				pushITP(&s, ch);
				break;

			case '(':					//�� ���ڰ� ��ȣ ���� �� ��,
				pushITP(&s, ch);		// ��ȣ ����
				break;

			case ')':					// �� ���ڰ� ��ȣ �� �� ��,
				top_op = popITP(&s);	// top_op�� ����� �����ڸ� ������
				while (top_op != '(')	// top�� ��ȣ�� �ƴ� �� ���� top_op�� ��� �����鼭 ��� �� 
				{
					printf("%c", top_op);	 
					top_op = popITP(&s);	
				}
				break;
			default:
				printf("%c", ch);		// ���ڴ� �׳� ���
				break;
		}
	}
	while (!is_emptyITP(&s))			// ��� ������ ������ ������ ��� 
		printf("%c", popITP(&s));
}

/*
int main(void)
{
	char* s = "(2+3)*4+9";
	printf("����ǥ�ü��� %s\n", s);
	printf("����ǥ�ü��� %s\n", s);
	infix_to_postfix(s);
	printf("\n");
	return 0;

}
*/