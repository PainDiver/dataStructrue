// ��� ���� ������ �ִܰ�θ� ã�� �˰���
// 2���� �迭�� �̿��� 3�߹ݺ��� ��

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType
{
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];		// ���� ��ķ� ����ġ ǥ��
}GraphTypeF;

int A[MAX_VERTICES][MAX_VERTICES];		// 

int distance_f[MAX_VERTICES];			// �Ÿ� �迭
int found_f[MAX_VERTICES];				// ������Ʈ �迭

void floyd(GraphTypeF* g, int start)		//floyd��� O(n^3)�� �ð����⵵�� ������.
{													
	int i, j, k;
	for (i = 0; i < g->n; i++)		//������ ������ŭ ó�� ����ġ�� A���ٰ� �ʱ�ȭ���ش�.
		for (j = 0; j < g->n; j++)
			A[i][j] = g->weight[i][j];
	
	printf("������Ʈ ��\n");
	for (i = 0; i < g->n; i++)		//�ʱ� ������Ʈ ��
	{
		for (j = 0; j < g->n; j++)
		{
			printf("%d ", A[i][j]==INF?-1:A[i][j]);
		}
		printf("\n");
	}
	printf("\n");


	for (k = 0; k < g->n; k++)					//�ٽɺκ�
	{
		for (i = 0; i < g->n; i++)				
			for (j = 0; j < g->n; j++)				
				if (A[i][k] + A[k][j] < A[i][j])		//������Ʈ�� �ϱ� ���� ������, ���ο� ���� ���� �Ÿ����� ���ƾ� �Ѵٴ���	
					A[i][j] = A[i][k] + A[k][j];		
													//��ķ�ġ��, ������� ���ο�� �ش��ϴ�, 0�� ���İ��� ������ �Ÿ��� ������Ʈ��,
													// i���� j�ΰ������� �Ÿ���, A[i][0]+A[0][j]�̴�.
													// 1�� ��ġ�� A[i][1]+A[1][j], ��, �� ���� n���� ���ؼ� �Ѵ���, ���� ���� ���� ������Ʈ��


		printf("������Ʈ %dȸ\n",k+1);
		for (i = 0; i < g->n; i++)					//�÷��̵��� ����� ����������� ��� �������� ���� ����� ��Ÿ����.
		{											//���ͽ�Ʈ��� ���������� �������� �ؼ� ��� �������� ���� ����� ��Ÿ����.
			for (j = 0; j < g->n; j++)
			{
				printf("%d ", A[i][j] == INF ? -1 : A[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	

}

/*
int main(void)
{
	GraphTypeF g = { 7,
	{{0,7,INF,INF,3,10,INF},
	{7,0,4,10,2,6,INF},
	{INF,4,0,2,INF,INF,INF},
	{INF,10,2,0,11,9,4},
	{3,2,INF,11,0,INF,5},
	{10,6,INF,9,INF,0,INF},
	{INF,INF,INF,4,5,INF,0},}
	};

	floyd(&g, 0);
	return 0;
}
*/