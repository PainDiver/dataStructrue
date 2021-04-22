#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define NUMOFATM 3

// 201600974 �����а� ��ȿ��

// �⺻����: ATM 3�밡 ���Ḯ��Ʈ�� ������� double-edged ť�� �̷�� ����, �� ATM���� front�� rear�� ������ �ְ�, �� front�� rear�� Client ����ü�� ����Ų��.
// Client����ü�� �մԵ��� ������ ��Ÿ���� �����ͷμ�, ť�� ����̴�. ����, �� Client����ü�� nextPerson, prevPerson�̶�� ���߿��Ḯ��Ʈ ��带 ������ �ִ�.
// �Ѹ����, ���߿��Ḯ��Ʈ���(Client)�� ��ҷ� �ϴ� ���Ḯ��Ʈ�� ������� double-edged ť(ATM)�� �ǹ��Ѵ�.


bool isPrime(int n)
{
	for (int i = 2; i < n; i++)		//�Ҽ��� Ȯ���ϴ� �Լ�, �̵��� ����Ż �̺�Ʈ�� ���� ����
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

typedef struct Client {	// ť�� ��ҷν� �۵��� Ÿ�� 
	int number;			//���� ��ȣ, vip����, �ҿ�ð��� ������ ����ü
	bool vip;
	int workTime;
	Client* nextPerson;
	Client* prevPerson;
} Client;


typedef struct {		
	Client* front, * rear;	//���Ḯ��Ʈ�� �̷���� ť, front�� rear�� ������ �ִ� ������ double edged queue �̴�.
	int time;				//�մ��� ATM�� �� ����ϴ� �ð�
	int sumOfWaitedTime;	//ATM�� ����ϱ� ���� �� ��ٸ� �ð�
	int jobsDone;			//ATM�� ���� ������
	int numOfClients;		//��ٸ����ִ� �մ� ��
	int sumOfvisitor;		//�湮�� ��
} LinkedQueueType;


bool is_empty(LinkedQueueType* q)
{
	return (q->front == NULL);		// ť�� ����� Ȯ���ϴ� �Լ�
}

void enqueueFront(LinkedQueueType* q, Client input)				//vip�뵵�� ���� enqueueFront�Լ�
{
	Client* temp = (Client*)malloc(sizeof(Client));				//������ ��带 �������� �Ҵ�
	temp->number = input.number; 								// ������ ����
	temp->vip = input.vip;
	temp->workTime = input.workTime;
	temp->nextPerson = q->front;								// �Ǿ����� ��ť�ϴ� �Լ��̹Ƿ�, ����� �� ��带 ���� ť�� front�� ����
	temp->prevPerson = NULL;									// �� ���� �����Ƿ� NULL
	if (is_empty(q))
	{
		q->front = temp;
		q->rear = temp;
	}
	else
	{
		q->front->prevPerson = temp;						// ���� ť�� �����ʾҴٸ�, ť�� front�� �ش��ϴ� ����� prev�� ���� ����� ���� �ְԵ�
		q->front = temp;									// �׸���, front�� ��� ������ ���� �ش�.
	}
}

void enqueue(LinkedQueueType* q, Client input)
{
	Client* temp = (Client*)malloc(sizeof(Client));			//��� ���� �Ҵ����� ����
	temp->number = input.number; 							// ������ ����
	temp->vip = input.vip;
	temp->workTime = input.workTime;
	temp->nextPerson = NULL; 								// ����� enqueue�� �޺κ����� �����Ƿ�, next�� �ش��ϴ� ��尡 ����.
	temp->prevPerson = q->rear;								// prev�� ť�� rear�κ����� �������ش�.
	if (is_empty(q)) { 										
		q->front = temp;											
		q->rear = temp;
	}
	else 
	{ 													// ť�� ������ �ƴϸ�
		q->rear->nextPerson = temp;						// ���� �������� ��ġ�ϴ� ��尡 �� ��带 �����Ѿ��ϹǷ� next�� ��� ������ ��忡 ����
		q->rear = temp;									// �׸��� ������ ���� ��� ������ ��尡 �ȴ�.
	}

}

Client dequeue(LinkedQueueType* q)
{
	if (is_empty(q)) {									// ���Ḯ��Ʈ�̹Ƿ�, full�� �������� ������, empty�� ������
		fprintf(stderr, "ť�� �������\n");				// ����ó��
	}
	Client* temp = q->front;							// ������ �����͸� ��� temp�� �Ű� ��
	Client data;										// temp���� ��� �����͸� ��ƿ� data��ü ��������
	data.number = temp->number; 						// �����͸� ������.
	data.vip = temp->vip;
	data.workTime = temp->workTime;
	q->front = q->front->nextPerson;					// dequeue�ϱ� �� ���� �����Ѵ�, �׷��Ƿ� front�� front�� next�� ����, ���� next��尡 ������ NULL�� ������
	if(q->front!=NULL)									// ���� ����� ������尡 NULL�� �ƴϸ� � ���� �����Ѵٴ� �ǹ��̹Ƿ�, �� ����� �� ��带 NULL�� ����
		q->front->prevPerson = NULL;
	else  	// ���� ����
		q->rear = NULL;									// dequeue�� �ߴµ� NULL�� ���, �ƿ� ������ �����̹Ƿ� rear�� NULL�� ����, front�� ���κп��� �˾Ƽ� NULL�� ������ �ȴ�.
	free(temp); 										// �����޸� ����
	return data; 										// �ӽ� ������ ��ȯ

}

void init_LinkedQueue(LinkedQueueType* q)
{
	for (int i = 0; i < NUMOFATM; i++)					//ATM�⸦ �ʱ�ȭ�ϴ� �κ�
	{													
		(q + i)->front = NULL;
		(q + i)->rear = NULL;
		(q + i)->jobsDone = 0;
		(q + i)->numOfClients = 0;
		(q + i)->sumOfvisitor = 0;
		(q + i)->sumOfWaitedTime = 0;
		(q + i)->time = 0;
	}

}


LinkedQueueType* GetLeastCrowdedATM(LinkedQueueType* q)
{
	int numOfPeople = 100;			//���� ���� ��⿭�� ���� numOfPeople����, ó�� 100�� ū �ǹ� ����.
	int pos = 0;					//���������� �� ��° ATM�� ���� ���� ������ ��ȯ�ϴ� pos����
	int same = 0;					//��� ���� ������ Ȯ���ϴ� same����

	int time[NUMOFATM] = { NULL };	//��� ATM�� ��⿭�� ���ٸ� ������ ó���ϳ�, ATM ��� �߿��� �ش� ����� ������� ���� ������ �ǴܵǹǷ�
									//�׶��� ������ �ƴ�, ATM�� time�� 0(�������������)�� ������ ���� ���� �Ͽ���. �� �� ���Ǵ� ������.

	for (int i = 0; i < NUMOFATM; i++)
	{
		time[i] = (q + i)->time;						//�� ATM�� ����ܿ��ð��� �����´�.
		if ((q + i)->numOfClients < numOfPeople)		//ATM�� ���� �ٿ� ���ִ� ��� ���� ���ذ���, ��� ���� ������ Ȯ��
		{
			numOfPeople = (q + i)->numOfClients;		// ���� ��⿭�� ª�� ��
			pos = i;									// �ش� ATM �ε��� ����
		}
		else if ((q + i)->numOfClients == numOfPeople)	//ATM�� ���� �� ���ִ� ����� ��� ���� �� same���� �ø�
		{
			same++;
		}
	}
	if (same == NUMOFATM - 1)		//same������ 2�� ��, �� ��� ATM�⿡ ���ִ� ��� ���� ���� �� ��, (��ó�� ATM��� ���ԾȵǹǷ�)
	{
		int c=0;
		for (int i = 0; i < NUMOFATM; i++) //������, ATM��� ���� ����� ����ٷ� ���ԾȵǹǷ�, �ʹݿ� ������� ATM ������̶� ��ٷ��� �Կ��� �ұ��ϰ� ��⿭�� 0�̶� ����� ATM�� �ΰ�, �װ����� �� �� ����
		{									//����� ATM�� Ž�� �Ѵ�.
			if (time[i] == 0)
			{
				pos = i;
				c++;
			}
		}
		if (c == NUMOFATM)					//ATM�� ��� ����� ���� ��,
			pos =rand() %3;
	}
	return (q + pos);					//�ش� ATM���� �ּ� ��ȯ
}

void CheckWaitedTime(LinkedQueueType* q)
{
	for (int i = 0; i < NUMOFATM; i++)
	{
		(q + i)->sumOfWaitedTime += (q + i)->numOfClients;		// �� ATM ��⿭�� �ִ� ����� 5���� ��, 1���� ������, �� ��ٸ� �ð��� 5�� ������ �ȴ�. ���߿� �� �湮�� ���� ���� ����
	}
}

//	����׿� �Լ�, ����ϸ� �� �и��� ATM�� ��⿭�� �ð�ȭ�Ͽ� �� �� ����
void printQueue(LinkedQueueType* q)
{
	for (int i = 0; i < NUMOFATM; i++)
	{
		Client* current;
		current = (q + i)->front;
		printf("\n--------------------------\n%d�� ATM�� �����\t", i + 1);
		while(current!=NULL)
		{
			printf("| %d |",current->number);
			current = current->nextPerson;
		}
		printf("\n--------------------------\n");
	}
}


void Work(LinkedQueueType* q, int clock, int minutes)
{


	Client* temp = NULL;						// ť���ִ� ��ҵ��� ��ȸ�ϱ� ���� Client ����ü ������
	Client* temp2 = NULL;	
	for (int i = 0; i < NUMOFATM; i++)			//�� ATM�� ������ ���� ���۵��� �Ѵ�.
	{
		if ((q + i)->time > 0)					// �۾��Ϸ��ܿ��ð��� 0�� �ƴҰ�� ��� �پ��� ��
		{
			(q + i)->time--;					
		}
		CheckWaitedTime(q);						// ��ٸ� �ð� ���


		temp = (q + i)->front;					// ť�� front�� �����Ͽ�, �� �� Client����ü�� �޾Ƴ���, next�� ��ȸ�� ����
		if (is_empty((q + i)))					// ATM�� ����ִٸ� �ش� ATM�� ����
			continue;
		if ((minutes % 10) == 0)				//�� 10�и���, �Ҽ���ȣ�� ����������� �����Ե�,
		{										
												//�Ҽ���, �ش� �ε����� ���� queue���� ������Ų��.
			int k = (q + i)->numOfClients;
			for (int j = 0; j<k; j++)
			{
				temp2 = temp->nextPerson;		//temp2�� temp1�� ���� ������ ���ư��� ���ؼ� �ʿ��ϴ�. temp�� �����Ǹ� �����δ� ���� �������� ���ϱ� ����
				if (isPrime(temp->number))		// �Ҽ� Ȯ��
				{
					printf("\n%d�� %d�� - %d�� �� ��Ż��\n", clock, minutes, temp->number);		//�Ҽ� �Ͻ�, �ش� �ð��� �Ҽ� ��° ���� ������ �ǵ��� ���
					if (temp->prevPerson && temp->nextPerson == NULL)							// �������� Client����ü�� �ǵڿ� �ִ°��,
					{
						(q+i)->rear = temp->prevPerson;
						temp->prevPerson->nextPerson = NULL;									// ������ �� ��常 next�� NULL�� �����ϰ� ���� ��带 free
						free(temp);
					}
					else if (temp->prevPerson == NULL)											// �� ��尡 NULL�ΰ��, �� �� �տ��ִ� ��尡 ������ �����
					{
						dequeue(q + i);															// dequeue�� �ذ�
					}
					else if (temp->prevPerson && temp->nextPerson)								// �� ���� �� ��� ��� �����Ѱ��
					{
						temp->prevPerson->nextPerson = temp->nextPerson;		//�ش��ȣ�� ���� ���� �ճ�� �޳�� �̾��ֱ�
						temp->nextPerson->prevPerson = temp->prevPerson;
						free(temp);
					}
					(q+i)->numOfClients--;											//�� �� �������� ATM�� ��ٸ��� �ο� -1����
				}																
					temp = temp2;												// temp�� temp2�� ��� ���� ���� �̵���
			}
		}


		if ((q + i)->time == 0 && !is_empty(q + i))			// ATM ������� ��������ʰ�, time�� 0�̶��, ATM��� ���ο� �������Ͽ��� ����ϰ� �ؾ��Ѵ�.
		{
			Client firstClient = dequeue((q + i));					// �� �տ��ִ� ���� ��⿭���� ������Ű�� �����͸� ������ش�.
			(q+i)->numOfClients--;									// �� �� �پ����� ATM�� ��⿭ 1���� ���δ�.
			printf("\n%d�� %d�� - %d�� ��(%d�� �ҿ�)�� %d�� ATM���� ���񽺸� ������ %s\n", clock, minutes, firstClient.number, firstClient.workTime, i + 1, firstClient.vip ? "vip��" : "normal��");
			(q + i)->time = firstClient.workTime;						// ATM��� �� ���� �����κ��� �ҿ�ð��� �޴´�.
			(q + i)->jobsDone++;										// �� ó�� ���� �ϳ� �÷��ش�.1
		}
	}

}


void PrintLast(LinkedQueueType* q)
{
	int sumOfWaitedTime = 0;
	int sumOfJobsDone = 0;
	int sumOfwaitingClients = 0;
	int sumOfVisitor = 0;
	for (int i = 0; i < NUMOFATM; i++)
	{
		sumOfWaitedTime += (q + i)->sumOfWaitedTime;		//ATM���� ������� ��⿭���� ��ٸ� �ð��� ������ ��
		sumOfJobsDone += (q + i)->jobsDone;					//ATM���� ������� ������ ��ģ ���� ������ ��
		sumOfwaitingClients += (q + i)->numOfClients;		//ATM���� ��ٸ����ִ� ������� ���� ������ ��
		sumOfVisitor += (q + i)->sumOfvisitor;				//ATM���� �湮��(�ٿ����־ ����)��� ���� ������ �� 
	}

	printf("\n�Ѹ� �� ��������� %d�� ��ٸ�\n ", sumOfWaitedTime / sumOfVisitor); //��� ��ٸ��ð�/��� �湮�ѻ��(��Ż�ڵ� ����) = ��� ��ٸ��ð�
	printf("%d���� ���� ������ ����\n", sumOfJobsDone);	//��� ��ó�� ��
	printf("10�� 59�� ���� %d ���� ��ٸ�������\n", sumOfwaitingClients);	// ��ٸ����ִ� ��� ����� ��
}

void freeAll(LinkedQueueType* q)
{
	for (int i = 0; i < NUMOFATM; i++)									//ATM�� �������� �Ҵ�Ǿ�������, �� ��� ���� ���������̴�.
	{																	//�׷��Ƿ� ��Ҹ� ��� �Ҵ������ϰ�, ATM�� ���������� �Ҵ����� ���־�� �Ѵ�.
		if ((q + i) != NULL)
		{
			if (!is_empty((q + i)))
			{
				for (int j = 0; j < (q + i)->numOfClients; j++)
				{
					dequeue((q + i));
				}
			}
		}
	}
	free((q));

}


int main()
{
	LinkedQueueType* ATMQueue;
	ATMQueue = (LinkedQueueType*)malloc(sizeof(LinkedQueueType) * NUMOFATM); //������ ATM������ŭ �����Ҵ�
	init_LinkedQueue(ATMQueue);												//�ʱ�ȭ
	srand(time(NULL));														//���� �õ� ����

	bool hourElapsed = false;			//1�ð��� �������� ���������� Ȯ���ϴ� bool���� (���������� ���� 9��~10�� �̹Ƿ� booló����)
	int minutes = 0;					//�� ����

	for (int i = 0; i < 119; i++)
	{
		minutes = (minutes + 1) % 60;	//minutes�� 119�� �ö�, 60���������� �ٽ� 0����
		if (minutes == 0)				//60���������� hourElpased true(1)�κ�ȯ
			hourElapsed = true;
		
		Client newOne = { minutes, (rand() % 10) == 5 ? true : false , (rand() % 9) + 2 , NULL };		// ���� �� ������ (��ȣ, vip����, worktime ,nextnode)������ ����
		LinkedQueueType* chosenATM;							// ����� ���� ���� ATM�� ã�Ƽ� �����ϱ� ����
		chosenATM = GetLeastCrowdedATM(ATMQueue);			// ����� �������� �� ã��

		if (newOne.vip == true)							// ���� ���� vip�� ��, enqueueFront�γ���
			enqueueFront(chosenATM, newOne);			//���õ� ATM�� ���ο� �� ������ �߰�
		else										
			enqueue(chosenATM, newOne);					// vip�� �ƴ� ��, �ڷ� �߰�
		chosenATM->sumOfvisitor++;						//�߰� ��, �湮�ڼ�, ��⿭ ������Ŵ
		chosenATM->numOfClients++;
		Work(ATMQueue, 9 + hourElapsed, minutes);		//work�Լ��� ATM�� �۵��ϰ� ����, (ATM, 1�ð��������� ��������������, ��) �Ű������� �Է�
		//printQueue(ATMQueue);							//����׿� �Լ�, ����ϸ� �� �и��� ��⿭�� ��� �Ǵ��� �ð������� �ľǰ���
	}
	PrintLast(ATMQueue);									// �������� �䱸�ϴ� ���׵� ���
	
										
	freeAll(ATMQueue);										// ������ ��� �����Ҵ� ����

	return 0;
}