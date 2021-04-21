#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100
#define MAZE_SIZE 6

typedef struct elementM
{
	short r;
	short c;
}elementM;					// ���ÿ� ���� �ڷ����� �׻� �ٲ� �� �����Ƿ� typedef��

typedef struct StackTypeM
{
	elementM data[MAX_STACK_SIZE];
	int top;
}StackTypeM;

elementM here = { 1,0 }, entry = { 1,0 };

char maze[MAZE_SIZE][MAZE_SIZE] =
{
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'}
};



void init_stackM(StackTypeM* s)			// �ʱ�ȭ�� top�� -1�� ����鼭 ����
{
	s->top = -1;
}


int is_emptyM(StackTypeM* s)
{
	return (s->top == -1);					// ��Ұ� ���� ���� -1�� ����Ŵ
}

int is_fullM(StackTypeM* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));	// ��Ұ� ���� �� ���� MAX-1, top�� MAX�� �ε��������� �Ѿ
}

void pushM(StackTypeM* s, elementM item)
{
	if (is_fullM(s))
	{												// ���� ��ȭ ����ó�� ��,
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->data[++(s->top)] = item;						// top�� 1 �ø��� ���ÿ� ���� �־� ��
}

elementM popM(StackTypeM* s)
{
	if (is_emptyM(s))								//��Ұ� ����� �� ����ó��,
	{
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else return s->data[(s->top)--];					// ���ÿ� top ���� ���� �� -1 ����
}

void push_loc(StackTypeM* s, int r, int c)				// r,c ���ؿ��� �շ��ִ� ���� ���ÿ� �ְ� ��
{
	if (r < 0 || c < 0) return;							// r,c�� ������ 0 �̻�
	if (maze[r][c] != '1' && maze[r][c] != '.')			// ���̸� �ȵǸ�, �Դ����̸� �ȵ�
	{											
		elementM tmp;									// ��Ҹ� �����
		tmp.r = r;										
		tmp.c = c;
		pushM(s, tmp);									//�ո���ǥ�� ���ÿ� ����
	}

}

void maze_print(char maze[MAZE_SIZE][MAZE_SIZE])			// ���� ����
{
	printf("\n");
	for (int r = 0; r < MAZE_SIZE; r++)						//�� ���
	{
		for (int c = 0; c < MAZE_SIZE; c++)
		{
			printf("%c", maze[r][c]);
		}
		printf("\n");
	}

}

int main()
{
	int r, c;
	StackTypeM s;
	
	init_stack(&s);								//���� �ʱ�ȭ
	here = entry;								// ������,������ ����
	while (maze[here.r][here.c] != 'x')			// ���� ��ġ�� �������� �ƴҶ� ���� ��� ã��
	{
		r = here.r;
		c = here.c;
		maze[r][c] = '.';						// �鸰 ��ġ�� .���� ǥ��
		maze_print(maze);						// ��� �� ���� �鸱 �� ���� ��� ���
		push_loc(&s, r - 1, c);					// �¿� ���Ʒ� �� üũ
		push_loc(&s, r + 1, c);
		push_loc(&s, r , c-1);
		push_loc(&s, r, c+1);

		if (is_emptyM(&s))						// ������ ��� �� �̻� �� ���� �����Ƿ� ����
		{
			printf("����\n");
		}
		else
			here = popM(&s);					// ������ �����ʾҴٸ� ��� pop�ϸ鼭 �� ��ǥ�� here�� ǥ���Ͽ� ������
	}
	printf("����");								// ������ ����

	return 0;
}