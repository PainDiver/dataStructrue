// Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void selection_sort(int list[], int n)
{
	int i, j, least, temp;
	for (i = 0; i < n - 1; i++)
	{
		least = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[least]) least = j;
		SWAP(list[i], list[least], temp);

		printf("%d��° ȸ��", i);
		for (int k = 0; k < n; k++)			//ȸ������ ����ϱ�
			printf("%d ", list[k]);
		printf("\n");
	}
}

//�������������� ,��Ƚ�� O(n^2)��, �̵�Ƚ���� 3(n-1), O(n)
// ��ü �ð��� ���⵵�� O(n^2)��

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


	selection_sort(list, n);
	for (i = 0; i < n; i++)
		printf("%d ",list[i]);
	printf("\n");
	return 0;
}
*/
