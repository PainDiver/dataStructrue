#include <stdio.h>
#include <Stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef struct elementB
{
	int id;
	int arrival_time;
	int service_time;

}elementB;

typedef struct QueueTypeB
{
	elementB data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueTypeB;

void errorB(char* message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queueB(QueueTypeB* q)
{
	q->front = q->rear = 0;				//ȯ�� ť�� ���� ť�� �޸� 0���� ������, �ʱ⿡ �ε��� 0�κ��� ��������·� ť�� ä����, �� �迭������ -1 ��ŭ ���尡��
}

int is_emptyB(QueueTypeB* q)
{
	return (q->front == q->rear);		// ����ť�� ���������� front�� rear�� ������ ���������
}

int is_fullB(QueueTypeB* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);		// ť�� �������ε���+1 �� ť������� ������, �� ������ ���� front�� �� 
}

void enqueueB(QueueTypeB* q, elementB item)
{
	if (is_fullB(q))
		errorB("ť�� ��ȭ����.\n");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;				// rear�� +1 �ϰ� ť ������� ���� ���������� �ȴ�.
	q->data[q->rear] = item;								// �׸��� �� �ε����� ���� �ְ� ��, ��Ҹ� �ֱ� ���� �ε����� 1�ø���, ���� ���������� �����ϴ� ��
}

elementB dequeueB(QueueTypeB* q)
{
	if (is_emptyB(q))
		errorC("ť�� ����\n");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;				// dequeue �� ��, �ٷ� �ش� �ε����� pop�ϴ� ���̾ƴ϶�,
	return q->data[q->front];								// front�� 1�� �ø��� ť ������� ���� ���������� ä�� �� ��, �� �ε��� ���� ��ȯ�Ѵ�.
}

int main(void)
{
	int minutes = 60;
	int total_wait = 0;
	int total_customers = 0;
	int service_time = 0;
	int service_customer;
	QueueTypeB queue;
	init_queueB(&queue);

	srand(time(NULL));
	for (int clock = 0; clock < minutes; clock++)
	{
		printf("����ð� =%d\n", clock);
		if( ( rand()%10) < 3)
		{
			elementB customer;
			customer.id = total_customers++;
			customer.arrival_time = clock;
			customer.service_time = rand() % 3 + 1;
			enqueueB(&queue, customer);
			printf("�� %d�� %d�п� ���ɴϴ�. ����ó���ð� = %d��\n", customer.id, customer.arrival_time, customer.service_time);
		}
		if(service_time>0)
		{
			printf("�� %d ����ó�����Դϴ�.\n", service_customer);
			service_time--;
		}
		else
		{
			if (!is_emptyB(&queue))
			{
				elementB customer = dequeueB(&queue);
				service_customer = customer.id;
				service_time = customer.service_time;
				printf("�� %d�� %d�п� ������ �����մϴ�. ���ð��� %d���̾����ϴ�.\n", customer.id, clock, clock - customer.arrival_time);	
			}

		}
	
	}
	printf("��ü ��� �ð�= %d��\n", total_wait);
	return 0;
}