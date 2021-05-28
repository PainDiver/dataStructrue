#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y,t)((t)=(x), (x)=(y), (y)=(t))

void BubbleSort(int list[], int n)
{
	int i, j, temp;
	for (i =n-1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (list[j] > list[j + 1])
				SWAP(list[j], list[j + 1], temp);
		}


		printf("%d��° ȸ��", i);
		for (int k = 0; k < n; k++)			//ȸ������ ����ϱ�
			printf("%d ", list[k]);
		printf("\n");
	}

}


// ��Ƚ���� �ֻ�,���,�־� �׻� O(n^2)��
// �������� ���ĵ� �־��� ��� 3*��Ƚ���̸�
// �̹� ���ĵ� ��� �̵�Ƚ���� 0
// ����� ���� O(n^2)�̴�


/*
int main()
{
	int i;
	int n = 20;
	int list[20];

	srand(time(NULL));
	for (i = 0; i < n; i++)
		list[i] = rand() % 100;

	BubbleSort(list, n);
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;

}

*/