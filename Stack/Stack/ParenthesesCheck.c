#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

typedef int elementP;					// ���ÿ� ���� �ڷ����� �׻� �ٲ� �� �����Ƿ� typedef��

typedef struct StackTypeP
{
	elementP data[MAX_STACK_SIZE];
	int top;
}StackTypeP;

void init_stackP(StackTypeP* s)			// �ʱ�ȭ�� top�� -1�� ����鼭 ����
{
	s->top = -1;
}


int is_emptyP(StackTypeP* s)
{
	return (s->top == -1);					// ��Ұ� ���� ���� -1�� ����Ŵ
}

int is_fullP(StackTypeP* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));	// ��Ұ� ���� �� ���� MAX-1, top�� MAX�� �ε��������� �Ѿ
}

void pushP(StackTypeP* s, elementP item)
{
	if (is_fullP(s))
	{												// ���� ��ȭ ����ó�� ��,
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;						// top�� 1 �ø��� ���ÿ� ���� �־� ��
}

elementP popP(StackTypeP* s)
{
	if (is_emptyP(s))								//��Ұ� ����� �� ����ó��,
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];					// ���ÿ� top ���� ���� �� -1 ����
}


int check_matching(const char* in)
{
	StackTypeP s;							// �Լ������� ����� �ӽ� ����
	char ch, open_ch;						// ch�� ���ڿ��� �ѱ��ھ� �޾ƿ� ���� open_ch�� ���ó����� ��ȣ�� �޾ƿ� ����

	int i, n = strlen(in);					// i�� for�� ��ȸ��, n�� ���ڿ��� ����(NULL ���� ���� x)
	init_stackP(&s);						// ���� �ʱ�ȭ

	for (i = 0; i < n; i++)
	{
		ch = in[i];							
		switch (ch)
		{
		case '(': case '[' : case '{':		// ( [ { ó�� ��ȣ���� ���ڸ� ���� ��
			pushP(&s, ch);					// �ش� ���ڸ� ���ÿ� �����Ѵ�.
			break;
		
		case ')': case ']': case '}':		// ) ] } ó�� ��ȣ�� ���ڸ� ���� ��
			if (is_emptyP(&s)) return 0;	// ������ ������� Ȯ�� �ϰ�
			else
			{
				open_ch = popP(&s);			// ��������ʴٸ� pop���ؼ� open_ch�� �ִ´� 
				if ((open_ch == '(' && ch != ')' ||	//opench�� ��ȣ ���۹����ε�, ch�� ��ȣ �����ڰ� �ƴ� ��, ����
					(open_ch == '[' && ch != ']') ||
					(open_ch == "{" && ch != '}')))
				{
					return 0;
				}
			}

		}

	}
	if (!is_emptyP(&s))				// ��� ������ ������ ����� �־����
		return 0;				
	return 1;						// ���������� ��ĥ ��, 1�� ���ϵ�
}

/*
int main(void)
{
	char* p = "{A[(i+1)]=0;}";
	if (check_matching(p) == 1)
		printf("%s ��ȣ�˻� ����\n", p);
	else
		printf("%s ��ȣ�˻� ����\n", p);
	return 0;
}
*/