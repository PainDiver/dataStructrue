// ���� �������κ��� ����Ͽ� ����Ʈ�� ������ �ܰ������� Ȯ����
// ����Ʈ�����տ� ������ ���� �߿��� ������������ ����� ������ �����ϰԵ�

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 100
#define INF 1000

//kruskal �� ���� prim�� ������������ ����ؼ� ����Ʈ�� ������ Ȯ���س�����. 

typedef struct GraphTypePrim {
	int n;
	int weight[MAX_VERTICES][MAX_VERTICES];		//kruskal�� ����ġ ������ ����� �ݸ�, 
}GraphTypePrim;									//prim�� ���� ����� ����� ����ġ�� ǥ���� �� �̴�.

int selected[MAX_VERTICES];		//
int distance[MAX_VERTICES];		//

int get_min_vertex(int n)	//���� ����� ���� ���� ���� ������ ��ȯ��Ű�� �Լ��̴�.
{
	int v, i;
	for (i = 0; i < n; i++) 
	{
		if (!selected[i])		//�湮���� ���� ������ ã�� ����,
		{
			v = i;				//�湮�������� ���� v�� ã�Ƴ�
			break;
		}
	}
	for (i = 0; i < n; i++)		// ��� ã�Ƴ� v�� �ߺ����� �ʴ� �湮���� ���� �ٸ� ���� i�� ã�Ƴ���, �Ÿ��� ����
		if (!selected[i] && (distance[i] < distance[v]))
			v = i;				//i�� v�� �� ����� ������ ��ȯ �� ����
	return v;
}

void prim(GraphTypePrim* g, int s)		//prim MST �˰����� �ð����⵵ O(n^2), �ֹݺ����� ������ �� n��ŭ �ݺ�, ���ιݺ����� n�� �ݺ�
{										//sparse graph�� ���ؼ��� kruskal (������ ���ؼ�)
	int i, u, v;						//dense graph������ prim�� �����ϴ� (������ ���ؼ�)
	for (u = 0; u < g->n; u++)			
		distance[u] = INF;				//�ʱ⿡ ��� ������ ����� �ʱ�ȭ�����ش�.
	distance[s] = 0;					//���� ���õ� �������� �����Ұ��̹Ƿ�, ���� ������ �Ÿ��� 0 �̴�.

	for (i = 0; i < g->n; i++)			//����������ŭ �ݺ���
	{
		u = get_min_vertex(g->n);		//�ִܰŸ��� ã�� ���̴�. (ó���õ��ϸ� ���� ������ ����)
		selected[u] = true;				//�ִܰŸ������� �湮�ߴٰ� üũ��
		if (distance[u] == INF)			//���� �ִܰŸ� ������ ��� INF�� �� �̻� ������ϴ� return�ؾ��Ѵ�.
			return;
		printf("���� %d �߰�\n", u);		//���õ� ������ �߰��ϰ�, ����������ŭ, ���õ� �������� ������ ������ ã�´�.
		for (v = 0; v < g->n; v++)		
			if (g->weight[u][v] != INF)	//ã�µ� �����ϸ�, �� ã�� ������ �湮���ο�, �Ÿ��� ������Ʈ �Ǿ��ִ��� Ȯ���Ѵ�.
				if (!selected[v] && g->weight[u][v] < distance[v])					// �Ÿ��� ��뺸�� ū ���� ������Ʈ�� �ȵȰ��
					distance[v] = g->weight[u][v];			//�� �������� ���������� �Ÿ��� ����ġ�� ������Ʈ��
	}														// �� for���� �ʱ�ȭ�ǹǷ�, �� ���� �� n����ŭ ������Ʈ��
}
/*
int main(void)
{
	GraphTypePrim g = { 7,
	{{0,29,INF,INF,INF,10,INF},
	{29,0,16,INF,INF,INF,15},
	{INF,16,0,12,INF,INF,INF},
	{INF,INF,12,0,22,INF,18},
	{INF,INF,INF,22,0,27,25},
	{10,INF,INF,INF,27,0,INF},
	{INF,15,INF,18,25,INF,0}}
	};
	prim(&g, 0);
	return 0;
}
*/