// Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int sorted[20];

void sort_three(int* l,int* m,int* r)
{
	int temp;
	if (*l > *m)
		SWAP(*l, *m,temp);
	if (*m > *r)
		SWAP(*m, *r, temp);
	if (*l > *m)
		SWAP(*l, *m, temp);
}

int partition(int list[], int left, int right)
{
	

	int pivot, temp;
	int low, high;

	low = left;			//���ʼ�ȸ
	high = right + 1;	// �����ʼ�ȸ +1�� ������ ó���������ڸ��� --�ɰ��̱� ����
	pivot = list[left];	// �ǹ�, �� ���ʰ����� ������ ����
	
	do 
	{
		do
			low++;		//�������ڸ��� low�� �þ�� ���ʿ�ҿ��� �ٷ� �����ʿ��ִ� ���� �ǹ��̶� ���ϰԵ�
		while (low <= right && list[low] < pivot); //�ǹ����� �۰�, �����ʳ� �ε������� �����������ϸ� �ݺ�
			
		do
			high--;		// low��ȸ�� ������ high�� ��ȸ�ϱ� ������
		while (high >= left && list[high] > pivot); // high�� �ǹ����� ũ��, ���ʳ����� �������� ���ϸ� �ݺ� 
		
		if (low < high)		// �� �� ������ ���� ���� �������� ��, low�� high�� Ʈ���̵尡 �Ͼ 
			SWAP(list[low], list[high], temp);

	} while (low < high);	// �̸� ����ؼ� �ݺ��ϴٺ���, low�� high���� Ŀ���� ���� ��,

	SWAP(list[left], list[high], temp);	// �� �� high�� �ε������ִ� ��ҿ� �ǿ��ʰ��� �ٲ���
	return high;	// �׸��� �� high�� ���ο� ���ذ����� ��ȯ����
}


void quick_sort(int list[], int left, int right)
{
	
	if (left < right)
	{
		int q = partition(list, left, right);	// ó�� ��Ƽ���� ������ �� ������ �� �װ����� �ٽ� ��ȯȣ�� ����
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

// ��������� ���� ���� ���Ĺ��

// �� ���� ������������ ����ϴµ�, �������İ��� �޸� ��յ��ϰ� �����Ѵ�.
// �ǹ��� ����� �ǹ����� ������ ū ���� ������


// �ּ��ǰ��( ���� �յ��� ����Ʈ�� ���ҵǴ°��)
// �н��� ���� log(n) (Ʈ���� ����)�� �Ǳ� �����̴�.
// �н� �ȿ��� �񱳴� n�� �Ͼ
// �׷��� ��Ƚ���� n*log(n)
// �̵�Ƚ���� ��Ƚ������ ���⿡ ���� ������ ����

//�ݸ� �־��� ���, �ص��� �ұյ��� ����Ʈ�� ���ҵǴ°��
// �н��� ���� n�� �Ǹ� �� �н� �ȿ����� ��Ƚ���� n�̵Ǿ� �� ��Ƚ���� n^2�� �ȴ�.
// �̵�Ƚ���� ���ð� �����ϴ�.
// ������� �̹� ���ĵ� ����Ʈ�� �����Ұ�� 
// �ǹ��� ���� ������ �������ԵǴµ�, �� �� n^2�� �ð����⵵�� �����Եȴ�.

// �̸� ���ϱ� ���ؼ� �߰����� �ǹ����� �����ϸ� �ұյ� ������ ��ȭ�� �� �ִ�.

/*
int main()
{
	int i;
	int n = 20;
	int list[20];

	srand(time(NULL));
	for (i = 0; i < n; i++)
		list[i] = rand() % 100;

	printf("������: ");
	for (int k = 0; k < n; k++)			//ȸ������ ����ϱ�
		printf("%d ", list[k]);
	printf("\n");


	quick_sort(list, 0, n-1);

	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;
}
*/
