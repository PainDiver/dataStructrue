#include <stdio.h>
#include <stdlib.h>

void InsertionSort(int list[],int n)
{
	int i,j,key;
	for (i = 1; i < n; i++)
	{
		key = list[i];
		for (j = i - 1; j >= 0 && list[j] > key; j--)
			list[j + 1] = list[j];
		list[j + 1] = key;

		printf("%d��° ȸ��", i);
		for (int k=0; k < n; k++)			//ȸ������ ����ϱ�
			printf("%d ", list[k]);
		printf("\n");
	}

}


// ��κ� ���ĵǾ������� ȿ������, �ּ��� ��� ��Ƚ�� O(n)���� ����,
// ���ڵ尡 Ŭ ��� �Ҹ��ϴ�. �������̴�(Ű���� ���Ƶ� ���� �ȹٲ�)
// �־��� ��� �� Ƚ�� O(n^2) �̵�Ƚ�� O(n^2)�� ���´�. 



/*
int main()
{
	int i;
	int n = 20;
	int list[20];

	srand(time(NULL));
	for (i = 0; i < n; i++)
		list[i] = rand() % 100;

	InsertionSort(list, n);
	for (i = 0; i < n; i++)
		printf("%d ", list[i]);
	printf("\n");
	return 0;

}
*/