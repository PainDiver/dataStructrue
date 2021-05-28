
#include <stdio.h>
#include <stdlib.h>

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

void inc_insertion_sort(int list[],int first, int last, int gap)
{
	int i, j, key;
	for (i = first+gap; i <= last; i=i+gap) 
	{
		key = list[i];		// �ڿ��ִ� �� ����
		for (j = i - gap; j >= first && list[j] > key; j=j-gap)
			list[j + gap] = list[j]; //ù��°��ҿ� �ڿ��ִ� �� ����, ù��° ��Ұ� ���� �� ũ�� ��ü
		list[j + gap] = key;
	}

}

void shell_sort(int list[], int n)
{
	int i, gap;
	for (gap = n / 2; gap > 0; gap = gap / 2)
	{
		if ((gap % 2) == 0)
			gap++;				//gap�� ��Ұ������� 2�γ�����, ¦���� 1�� ���� Ȧ���θ���
		for (i = 0; i < gap; i++)
			inc_insertion_sort(list, i, n - 1, gap); // ����Ʈ, �ݺ�Ƚ��, ����������ε���, gap�� ����

		printf("%d��° ȸ��", i);
		for (int k = 0; k < n; k++)			//ȸ������ ����ϱ�
			printf("%d ", list[k]);
		printf("\n");
	}
}

// �������� ���������� ����ϰ� �ȴ�.
// ���������� ������� ���ĵ� ����Ʈ���� ����� ������,
// ���������� ��ҵ��� �̿��� ��ġ�θ� �̵��Ͽ�, ���� �̵��� ���� ��Ұ� ���ڸ��� ���ư���.
// ��ҵ��� �ָ� ������ ��ġ�� �̵��� �� ������ ���� �̵����� ������? ��� �������� ������ ���� ������

// �������� ��ü ����Ʈ�� ���� ������ �κи���Ʈ�� ������ ������ �κи���Ʈ�� ���������ϵ��� �Ǿ��ִ�. 
// �������, �����ε����� nĭ������ �����ϰ� ���ϴ� �����
// 5ĭ ��������, 3ĭ ��������, 1ĭ �������� - �̷������� �����ϴ� ���� �������̶��� 
// ������ġ�̵����� ���ڸ��� ã�� ���ɼ��� ũ��.
// �ð����⵵�� �־��� ��� O(n^2)�̰� ��������� O(n^1.5)�̴� 


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


	shell_sort(list, n);
	for (i = 0; i < n; i++)
		printf("%d ",list[i]);
	printf("\n");
	return 0;
}
*/
