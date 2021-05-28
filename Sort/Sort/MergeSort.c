// Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int sorted[20];

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left; j = mid + 1; k = left;	// i ~ mid , j ~ right�� �ɰ� ����

	while (i <= mid && j <= right)	//���ʺ��Ұ� �����ʺ����� ��ҵ��� ������ �����ʿ�Ҹ� �������������� ������ ����
	{
		if (list[i] <= list[j])
			sorted[k++] = list[i++];	// �������� sorted�� �ְ� ���ʿ��� �� ��Ҷ�� i�� ������Ŵ
		else
			sorted[k++] = list[j++];	// �������� j
	}								// i�� j ��, ���� ������ �� �� ��Ұ� ���� �̹� �� ���ĵǾ��ٸ�

	if (i > mid)					// ���������ִ� ���� ��Ҹ� �ѹ��� �� �ְ� �ȴ�.
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];

	for (l = left; l <= right; l++)	// sorted�� ������ �� �Ǿ������� �̰��� list�� �ٽ� �����
		list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;		//���� �����ε���, �������ε����� ���� ����
		merge_sort(list, left, mid);	// �ɰ��� ������ �������ΰ� ��� �ɰ��� 1:1���踣 �̷����,
		merge_sort(list, mid + 1, right); // �����ʵ� ��������
		merge(list, left, mid, right); // 1:1���� �ɰ��� ���� �պ� �����ϰ���
	
	}

}


// ũ�� n�� ����Ʈ�� �յ� �й��ϹǷ� log n���� �н�(����)�� �Ͼ��,
// �� �н����� ����Ʈ�� ��� ���ڵ带 n�� ���ϹǷ� n log n���� �񱳿����� �Ѵ�.

// �̵�Ƚ���� �� �н����� 2n�� �߻��ϹǷ� ��ü ���ڵ� �̵��� 2n*log(n)�� �߻��Ѵ�
// �պ������� ����Ʈ�� ������ ��, ����Ʈ�� �����ϴ� ����̴�.
// Divde, conquer, combine �̶� �Ͽ�, ���� ,���� ,������ �ܰ�� �̷���� �ִ�.

// �ð����⵵ ���,����,�־� O(n*log(n))�� ������.
// ���� �������̸� �������� �ʱ� �л� ������ ������ ���޴´�.

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


	merge_sort(list, 0,n-1);

	for (i = 0; i < n; i++)
		printf("%d ",list[i]);
	printf("\n");
	return 0;
}
*/
