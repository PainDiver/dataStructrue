#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int elementD;
typedef struct DequeTypeD
{
	elementD data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeTypeD;

void errorD(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_dequeD(DequeTypeD* q)				//���� ȯ��ť�� ���������� front,rear�� 0���� �ʱ�ȭ �ȴ�.
{
	q->front = q->rear = 0;
}

int is_emptyD(DequeTypeD* q)
{
	return (q->front == q->rear);			// ����ִ��� �� ���� front�� rear�� ������ �ȴ�.
}

int is_fullD(DequeTypeD* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);	//����á���� Ȯ���� ���� front��  rear+1 % ť������ ��
}

void deque_print(DequeTypeD* q)
{
	printf("DEQUE(front=%d rear = %d) =", q->front, q->rear);	
	if (!is_emptyD(q))
	{
		int i = q->front;
		do 
		{
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void add_rear(DequeTypeD* q, elementD item)
{
	if (is_fullD(q))
		errorD("ť�� ��ȭ����\n");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;		//���ʿ� ��Ҹ� �߰� �� ��, rear�� 1������Ű�µ�, ���� ȯ�� ť�̹Ƿ� rear+ 1 % MAX_QUEUE_SIZE
	q->data[q->rear] = item;
}

elementD delete_front(DequeTypeD* q)
{
	if (is_emptyD(q))
		errorD("ť�� �������\n");			
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;		//���� ��Ҹ� ���� �� ��, front�� 1������Ŵ, �� ���� rear+1 % MAX_QUEUE_SIZE
	return q->data[q->front];
}

elementD get_front(DequeTypeD* q)
{
	if (is_emptyD(q))
		errorD("ť�� �������\n");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];	// front�� ����ü�� ������� �ʰ�, 1ĭ �������� ����ϴµ�, �� ������ ����� ��ȭ�� �����ϱ� ���ؼ���.

}

void add_front(DequeTypeD* q, elementD val)
{
	if (is_fullD(q))
		errorD("ť�� ��ȭ����\n");
	q->data[q->front] = val;							// front �κп� �ٷ� ���� �ְ�, front�� 1ĭ ���ҽ�Ų��. front�� �ִ� ���� �ٷλ������ �����Ƿ� ����.
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

elementD delete_rear(DequeTypeD* q)
{
	int prev = q->rear;
	if (is_emptyD(q))
		errorD("ť�� ����\n");						// rear�� 1ĭ ���̰�, �ش� �κп� ���� �ְ� �ȴ�. rear�� front�� �޸� ��ȿ �����͸� ����Ű�� ����
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];		// prev�� ��� ����Ű�� ���� ��ȯ�ϱ� ���� �뵵
}

elementD get_rear(DequeTypeD* q)
{
	if (is_emptyD(q))
		errorD("ť�� ����\n");
	return q->data[q->rear];		// rear�κ��� ������ 
}

/*
int main(void)
{
	DequeTypeD queue;
	
	init_dequeD(&queue);
	for (int i = 0; i < 3; i++)
	{
		add_front(&queue, i);
		deque_print(&queue);
	}
	for (int i = 0; i < 3; i++)
	{
		delete_rear(&queue);
		deque_print(&queue);
	}
	return 0;
}
*/