#include <stdio.h>
#include <malloc.h>

typedef int elementQ;

typedef struct QueueNode
{
	elementQ data;
	struct QueueNode* link;
}QueueNode;


typedef struct
{
	QueueNode* front,*rear;					//ť�̹Ƿ� front�� rear�� ����Ű�� ������ (doubled edged queue��)
}LinkedQueueType;

void initQ(LinkedQueueType* q)
{
	q->front = NULL;
	q->rear = NULL;								// ť�� front�� rear�� NULL�� �Ͽ� �ʱ�ȭ
}

int is_emptyQ(LinkedQueueType* q)
{
	return (q->front == NULL);					// front�� ��ٴ� ���� �� ť�� �ƹ��͵� ���ٴ� ��
}

void enqueueQ(LinkedQueueType* q, elementQ item)
{
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));		//temp �����Ҵ� ��
	temp->data = item;												
	temp->link = NULL;												//������ ����
	if (is_emptyQ(q))											// �ʱ⿡ ť�� ����ִٸ� front�� rear�� �ڽ����� ������
	{
		q->front = temp;
		q->rear = temp;
	}
	else
	{															// ���� ���� ����ִٸ�, �� �ڿ��ִ� ��带 ���ݻ����� ���� �̾���
		q->rear->link = temp;									// rear�����ʹ� ��� ������ ���� ����
		q->rear = temp;
	}
}
void print_queue(LinkedQueueType* q)
{
	for (QueueNode* p = q->front; p != NULL; p = p->link)		// front���� �����ؼ� ���� �߿ö󰡸鼭 ���
		printf("%d->", p->data);								// ���ð� �ٸ��� ���ʺ��� ���������� �����
	printf("NULL\n");
}

elementQ dequeueQ(LinkedQueueType* q)
{
	if (is_emptyQ(q))
	{
		fprintf(stderr, "ť ��");
		exit(1);
	}
	else
	{
		QueueNode* temp = q->front;								// ������ ��ť ��带 �ӽ÷� �����Ͽ�
		int data = temp->data;									// �ش� ����� �����͸� ���ְ�
		q->front = q->front->link;								// front�����Ϳ� �ִ� ��带 ������ ���̹Ƿ�, q->front�� �������� ����
		free(temp);												// ���� front�� ����
		return data;
	}
}

int main(void)
{
	LinkedQueueType q;
	initQ(&q);
	enqueueQ(&q, 1);
	print_queue(&q);
	enqueueQ(&q, 2);
	print_queue(&q);
	enqueueQ(&q, 3);
	print_queue(&q);

	dequeueQ(&q);
	print_queue(&q);
	dequeueQ(&q);
	print_queue(&q);
	dequeueQ(&q);
	print_queue(&q);
	return 0;
}