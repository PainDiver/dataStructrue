// ����ġ �������. ������ 0,1�� ǥ���ϴ� ���� �ƴ�, ������� ����. ����Ǿ� �־ ��밪�� �ٸ���, ��Į�ڸ��� ������(����⿬��)
// ������� �ʾҴٸ� INF�� ǥ��

// ���ͽ�Ʈ�� �˰��� ,�÷��̵� �˰��� �ΰ��� ����

// ���ͽ�Ʈ��� 1->n������ �ִܰ��, �÷��̵�� n->n������ �ִܰ�� ��� �������� �ٸ� ��� ���������� �ִܰ��
// �� ����������, ���Ͻ� �迭���� ����� ���� ���� ����� �������� ���ԵǸ鼭,�ִ������� �����ϸ鼭, �ִܰ�κ���� ���Ͻ��迭�� ������Ʈ �س���(���������ϸ鼭 �Ÿ�����Ѵٰ����)
// 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 1000000

typedef struct GraphType 
{
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];
}GraphTypeP;

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for(i=0;i<n;i++)
		if (distance[i] < min && !found[i])
		{
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void dijkstra(GraphTypeP* g, int start)		//�Ϲ������δ� O(nlogn)�̳� ���⼱ �ð����⵵ O(n^2)��, ��� ������ ���ؼ� Ž���� �ϰ�, ������Ʈ�� �ϱ⶧��
{
	int i, u, w,j;
	for (i = 0; i < g->n; i++)
	{
		distance[i] = g->weight[start][i];
		found[i] = false;
	}
	found[start] = true;
	distance[start] = 0;
	for (i = 0; i < g->n - 1; i++)				//���ιݺ��� 2n�� �ܺ� n��, �� 2n^2�̳� ���ǥ��������� n^2
	{
		printf("distance :");
		for (j = 0; j < g->n; j++)
		{
			printf("%d ", distance[j] == INF ? -1 : distance[j]);
		}
		printf("\n");
		printf("found    :");
		for (j = 0; j < g->n; j++)
		{
			printf("%d ", found[j]);
		}
		printf("\n");

		u = choose(distance, g->n, found);		// min distance�� ã�� �� ����Ž���� �Ұ�� log n���� �ٱ� ������, O(nlogn)���� �� �� ����
		found[u] = true;
		for (w = 0; w < g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w] < distance[w])
					distance[w] = distance[u] + g->weight[u][w];
		
	}
}

/*
int main(void)
{
	GraphTypeP g = { 7,
	{{0,7,INF,INF,3,10,INF},
	{7,0,4,10,2,6,INF},
	{INF,4,0,2,INF,INF,INF},
	{INF,10,2,0,11,9,4},
	{3,2,INF,11,0,INF,5},
	{10,6,INF,9,INF,0,INF},
	{INF,INF,INF,4,5,INF,0},}
	};

	dijkstra(&g, 0);
	return 0;
}
*/