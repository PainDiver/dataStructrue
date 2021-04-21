#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef char elementF;					// ���ÿ� ���� �ڷ����� �׻� �ٲ� �� �����Ƿ� typedef��

typedef struct StackTypeF
{
	elementF data[MAX_STACK_SIZE];
	int top;
}StackTypeF;

void init_stackF(StackTypeF* s)			// �ʱ�ȭ�� top�� -1�� ����鼭 ����
{
	s->top = -1;
}


int is_emptyF(StackTypeF* s)
{
	return (s->top == -1);					// ��Ұ� ���� ���� -1�� ����Ŵ
}

int is_fullF(StackTypeF* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));	// ��Ұ� ���� �� ���� MAX-1, top�� MAX�� �ε��������� �Ѿ
}

void pushF(StackTypeF* s, elementF item)
{
	if (is_fullF(s))
	{												// ���� ��ȭ ����ó�� ��,
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;						// top�� 1 �ø��� ���ÿ� ���� �־� ��
}

elementF popF(StackTypeF* s)
{
	if (is_emptyF(s))								//��Ұ� ����� �� ����ó��,
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];					// ���ÿ� top ���� ���� �� -1 ����
}



int eval(char exp[])
{
	int op1, op2, value, i = 0;				// op1 op2�� ���þȿ��ִ� ���� �����ͼ� ������ �� ���� �ش��ϴ� �κ�
	int len = strlen(exp);					// ���ڿ� ����
	char ch;									
	StackTypeF s;							// �Լ��� ����
	
	init_stackF(&s);							// ���� �ʱ�ȭ
	for (i = 0; i < len; i++)
	{
		ch = exp[i];
		if (ch != '+' && ch != '-' && ch != '*' && ch != '/')	// ���ڿ��� �����ڰ� �ƴҰ�� ���ÿ� �ְԵ�
		{
			value = ch - '0';							// ���ÿ� ���� ��, ���ڿ��� ���� ���� ���ڷ� ��޵ǹǷ� int�� ������ �ƽ�Ű�ڵ带 ���缭 �Է�
			pushF(&s, value);							
		}
		else
		{										// ch�� �������� ���
			op2 = popF(&s);						//op ������ ���� ������ �� ���� 
			op1 = popF(&s);						
			switch (ch)
			{
			case '+': pushF(&s, op1 + op2);		//+�ϰ�� op1��op2�� ���ؼ� ���ÿ� ����
				break;
			case '-': pushF(&s, op1 - op2);		//-�ϰ�� op1��op2�� ���� ���ÿ� ����
				break;
			case '*': pushF(&s, op1 * op2);		//+�ϰ�� op1��op2�� ���ؼ� ���ÿ� ����
				break;
			case '/': pushF(&s, op1 / op2);		//+�ϰ�� op1��op2�� ������ ���ÿ� ����
				break;
			}
		}

	}
	return popF(&s);								//���������� ���Ǿ� �����ִ� ���� pop�ϸ鼭 ������
}
/*
int main()
{
	int result;
	printf("����ǥ����� 82/3-32*+\n");
	result = eval("82/3-32*+");
	printf("������� %d\n", result);
	return 0;
}
*/