// Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define DIGITS 4
#define BUCKETS 10

typedef struct QueueNode
{
	int num;
	struct QueueNode* next;
}QueueNode;


typedef struct QueueType
{
	struct QueueNode* front;
	struct QueueNode* rear;
}QueueType;

bool is_empty(QueueType* q)
{
	if (q->front == NULL)
		return true;
	else
		return false;
}

void init(QueueType* q)
{
	q->front = NULL;
	q->rear = NULL;
}

void enqueue(QueueType* q, int num)
{
	QueueNode* temp;
	temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->num = num;
	temp->next = NULL;
	if (!is_empty(q))
	{
		q->rear->next = temp;
		q->rear = temp;
	}
	else
	{
		q->front = temp;
		q->rear = temp;
	}
}

int Dequeue(QueueType* q)
{
	QueueNode* temp = q->front;
	int num;
	q->front = temp->next;
	num = temp->num;
	free(temp);

	if (q->front == NULL)
		q->rear = NULL;

	return num;
}



void RadixSort(int list[], int n)
{
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];

	for (b = 0; b < BUCKETS; b++)
		init(&queues[b]);
												// ��Ŷ�� queueType���� �־��� 
	for (d = 0; d < DIGITS; d++)				// DIGIT, �� ���� �ڸ�����ŭ �ݺ���
	{
		for (i = 0; i < n; i++)
			enqueue(&queues[(list[i] / factor) % 10], list[i]);	// ó�� �ڸ����� �����Ͽ� �־��ְ�
		for (b = i = 0; b < BUCKETS; b++)
		{
			while (!is_empty(&queues[b]))		// �ٽ� ����, 
				list[i++] = Dequeue(&queues[b]);
		}											// ������ �ڸ�����ŭ �ݺ��� ��, ��� ���� ���ĵɰ���
		factor *= 10;
	}
}


// ������ ���� �ڸ���(1���ڸ�)���� �������� �̵���Ų��.
// �� �� ���� ����(1���ڸ��� ����) ���Ͽ��� ���������� ������.
// �� ���� ���� �ڸ���(10���ڸ�)����  �ش� �������� �̵���Ų��.
// �� �� �ٽ� ���� ����(10���ڸ��� ����) ���Ͽ��� ���������� ������ 10���ڸ� ���� ���Ľ�ų �� �ִ�.

// ���Ͽ� �ֱ��� �а�, ���Ͽ��� �� �� �д´�. d�� �ڸ��� �����,  d * 2n���� �о�� �ϴ¼���
// �� �ð����⵵�� O(dn)�� �ȴ�.

// ������ ������ Ű�� ǥ������� ������ �ִ�, 10������ 10��, ���ĺ��� 26�� ó��
// 
// 32��Ʈ ������ ���, 8��Ʈ��������, 2^8��ŭ�� ���� ǥ���ؾ��ϴ� ��Ĺ�� 256���� �þ��, �ʿ��� �н��� ���� 4�� �پ���
// 4��Ʈ�� ������ ��Ĺ�� 2^4��ŭ�� ���� ǥ���ؾ��ϴ� 16���� ������ �ʿ��ϰ�, �ʿ��� �н��Ǽ��� 8,
// 2��Ʈ�� ������ ��Ĺ�� 4��, �ʿ��� �н��� ���� 16


int main()
{
	int i;
	int n = 20;
	int list[20];

	srand(time(NULL));
	for (i = 0; i < n; i++)
		list[i] = rand() % 10000;

	printf("������: ");
	for (int k = 0; k < n; k++)			//ȸ������ ����ϱ�
		printf("%d ", list[k]);
	printf("\n");


	RadixSort(list, 20);

	for (i = 0; i < n; i++)
		printf("%d ",list[i]);
	printf("\n");
	return 0;
}
