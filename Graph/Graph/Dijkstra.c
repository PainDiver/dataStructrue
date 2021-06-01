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
	int weight[MAX_VERTICES][MAX_VERTICES];		//���ͽ�Ʈ��� ��������� �̿��ؼ� ����ġ�� ǥ����
}GraphTypeP;

int distance[MAX_VERTICES];						//�Ÿ�
int found[MAX_VERTICES];						// 

int choose(int distance[], int n, int found[])	// choose�Լ��� ���ݱ��� ������Ʈ�� ��������Ʈ�� �Ÿ�����Ʈ���� �޴´�.
{															
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for(i=0;i<n;i++)			//n���ݺ�
		if (distance[i] < min && !found[i])	// ���� ������Ʈ ���� ���� ������ �ִٸ�
		{									// �� �߿��� ���� ���� �Ÿ������ ������ �ִ� �ε����� ã�� ��ȯ�Ѵ�.
			min = distance[i];				// �� �κ��� ���� ��������Ž������ ������ �Ǹ� ���ͽ�Ʈ��� O(nlogn)�� �ð����⵵�� ���� �� �ְ� �ȴ�.
			minpos = i;
		}
	return minpos;
}

void dijkstra(GraphTypeP* g, int start)		//�Ϲ������δ� O(nlogn)�̳� ���⼱ �ð����⵵ O(n^2)��, ��� ������ ���ؼ� Ž���� �ϰ�, ������Ʈ�� �ϱ⶧��
{
	int i, u, w,j;
	for (i = 0; i < g->n; i++)			 
	{
		distance[i] = g->weight[start][i];		// �������������κ��� �Ÿ��� ���ϰ� ��
		found[i] = false;						// �������� ��δ� false�� ����
	}
	found[start] = true;						// ó�� �ڽ���ġ�� true�� �Ÿ� 0���� �������� 
	distance[start] = 0;						

	for (i = 0; i < g->n - 1; i++)				//O(n^2)
	{											// 
		printf("distance :");
		for (j = 0; j < g->n; j++)
		{
			printf("%d ", distance[j] == INF ? -1 : distance[j]);	//���� ���忡�� �� �����鿡 ���� �Ÿ��� ǥ���Ѵ�.
		}
		printf("\n");
		printf("found    :");
		for (j = 0; j < g->n; j++)
		{
			printf("%d ", found[j]);			// ���� ������Ʈ�� ���� ���� �����鿡 ���ؼ� 0�� ǥ���ϵ��� ����Ѵ�.
		}
		printf("\n");

		u = choose(distance, g->n, found);		// min distance�� ã�� �� ����Ž���� �Ұ�� log n���� �ٱ� ������, O(nlogn)���� �� �� ����
		found[u] = true;						// ���� ����� ���� �κ��� ã�� �̸� �������� ������Ʈ���Ѵ�.
		for (w = 0; w < g->n; w++)				// �� �κп����� ������Ʈ�� �� �� ������ ã��,
			if (!found[w])						// ���� ����� ���� �κ��� �Ÿ� + ������Ʈ�� �ȵ� ������ ��� < ������Ʈ�� �ȵ� ������ �Ÿ� �� ��,
				if (distance[u] + g->weight[u][w] < distance[w])	// ������Ʈ�� �ȵ� ������ �Ÿ� = ���� ����� ���� ������ �Ÿ�+ ������Ʈ�� �ȵ� ������ ���
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