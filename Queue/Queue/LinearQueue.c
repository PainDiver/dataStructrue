#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int elementL;					//�ڷ��� Ÿ���� �ٲ�������Ƿ�

typedef struct QueueTypeL				
{
	int front;						// ť�� �� ��
	int rear;						// ť�� �� ��
	elementL data[MAX_QUEUE_SIZE];	// ť�� �ڷḦ �迭�� ��Ÿ��, ũ�� ���� ����
}QueueTypeL;

void errorL(char* message)		//���� ��� �Լ�
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queueL(QueueTypeL* q)		// ť �ʱ�ȭ (���� ť�� front,rear�� -1�� �ʱ�ȭ)
{
	q->rear = -1;
	q->front = -1;
}

void queue_printL(QueueTypeL* q)		// ť�� ��� ��� ���
{
	for (int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if (i <= q->front || i > q->rear)		// ���� ��ȸ�ϴ� �κ��� front�� rear���̿� ���ٸ� ����� ���
			printf("  | ");
		else
			printf("%d| ", q->data[i]);			// ��ȸ�κ��� front�� rear ���̿� �ִٸ� ��� ���
	}
	printf("\n");
}

int is_fullL(QueueTypeL* q)
{
	if (q->rear == MAX_QUEUE_SIZE - 1)			// ť ��ȭ���´� MAX -1 ��  rear�� �˻�
		return 1;
	else
		return 0;
}

int is_emptyL(QueueTypeL* q)					// ť ������´� front�� rear���� ���ƾ� ��
{
	if (q->front == q->rear)
		return 1;
	else
		return 0;
}

void enqueueL(QueueTypeL* q, int item)		
{
	if (is_fullL(q))
	{
		errorL("ť�� ��ȭ����.\n");
		return;
	}
	q->data[++(q->rear)] = item;			// rear���� �ø� ��, �ش� �ε����� ��Ҹ� ���� (rear�� -1���� �밡�ϴ� 1�ø��� ����)
}

int dequeueL(QueueTypeL* q)
{
	if (is_emptyL(q))
	{
		errorL("ť�� �������.\n");
		return -1;
	}
	int item = q->data[++(q->front)];	//// front���� �ø� ��, �ش� �ε����� �ִ� ���� ��ȯ ( front�� -1���� �����ϴ� 1�ø��� ��ȯ)
	return item;
}


/*
int main(void)
{
	int item = 0;
	QueueType q;
	
	init_queue(&q);

	enqueue(&q, 10);
	queue_print(&q);
	enqueue(&q, 20);
	queue_print(&q);
	enqueue(&q, 30);
	queue_print(&q);

	item = dequeue(&q);
	queue_print(&q);
	item = dequeue(&q);
	queue_print(&q);
	item = dequeue(&q);
	queue_print(&q);

	return 0;
}
*/