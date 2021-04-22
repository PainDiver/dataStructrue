#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int elementC;

typedef struct QueueTypeC
{
	elementC data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueTypeC;

void errorC(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queueC(QueueTypeC* q)
{
	q->front = q->rear = 0;				//ȯ�� ť�� ���� ť�� �޸� 0���� ������, �ʱ⿡ �ε��� 0�κ��� ��������·� ť�� ä����, �� �迭������ -1 ��ŭ ���尡��
}

int is_emptyC(QueueTypeC* q)
{
	return (q->front == q->rear);		// ����ť�� ���������� front�� rear�� ������ ���������
}

int is_fullC(QueueTypeC* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);		// ť�� �������ε���+1 �� ť������� ������, �� ������ ���� front�� �� 
}

void queue_printC(QueueTypeC* q)
{
	printf("QUEUE(front=%d rear=%d) =", q->front, q->rear);
	if (!is_emptyC(q))
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

void enqueueC(QueueTypeC* q, elementC item)
{
	if (is_fullC(q))
		errorC("ť�� ��ȭ����.\n");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;				// rear�� +1 �ϰ� ť ������� ���� ���������� �ȴ�.
	q->data[q->rear] = item;								// �׸��� �� �ε����� ���� �ְ� ��, ��Ҹ� �ֱ� ���� �ε����� 1�ø���, ���� ���������� �����ϴ� ��
}

elementC dequeueC(QueueTypeC* q)
{
	if (is_emptyC(q))								
		errorC("ť�� ����\n");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;				// dequeue �� ��, �ٷ� �ش� �ε����� pop�ϴ� ���̾ƴ϶�,
	return q->data[q->front];								// front�� 1�� �ø��� ť ������� ���� ���������� ä�� �� ��, �� �ε��� ���� ��ȯ�Ѵ�.
}


/*
int main(void)
{
	QueueTypeC queue;
	int element;

	init_queueC(&queue);
	printf("������ �߰��ܰ�\n");
	while (!is_fullC(&queue))
	{
		printf("������ �Է��ϼ���.");
		scanf_s("%d", &element);
		enqueueC(&queue, element);
		queue_printC(&queue);
	}
	printf("ť�� ��ȭ����\n\n");

	printf("������ �����ܰ�\n");
	while (!is_emptyC(&queue))
	{
		element = dequeueC(&queue);
		printf("���� ����: %d\n", element);
		queue_printC(&queue);
	}
	printf("ť�� �������.\n");
	return 0;
}
*/