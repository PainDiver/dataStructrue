// �׷������� ��� ������ �����ϴ� Ʈ��, n���� ������ ������ �׷����� ����Ʈ���� n-1���� ������ ������.
// ABC ������ �� ������ ������ ȯ������ ����Ǿ� ������ ���� ��� A->B�� �����ְų� B->C�� �����ų� C->A�� ������ ���� ����
// ABCD�� ������ A->B->C->D�� ����Ǿ�����

//����Ʈ���� ��������� �� ��η� �� �������� ���� �ִ� Ʈ��
//dfs�� ���� �� ����

//�ּҺ�� ����Ʈ�� minimum spanning tree MST
//�������� �̵��ϴ� �Ϳ� ����� �ִٸ�, ��� ������ �����ϰ� ����� �ּ�ȭ �ϴ� ���� �ּҺ�� ����Ʈ��

// ����� ���� ���� ������ �ϳ��� Ž���ذ��� ������տ� �־��ְԵȴ�.
// ��������� ����Ŭ�� �̷�� ����� ��δ� ���ܸ� �ϰԵȴ�.


//union-find�˰��� 
//MST�� ����Ŭ�� �̷������ Ȯ���� �˰����� �ʿ��ϴ� -> union-find �˰���
//������������ ���ʴ�� ���鼭 �� ������ ���߿� ���� ������ ����Ǿ��ִ°�� ����Ŭ�� ��
// ABCDEFGHIJ ��尡 �ִٰ� �����ϰ�, ��Ʈ��尪���� -1�̶�� ���� ����
// ���� A�� B�� ����Ǿ��ִٸ�, B�� ��Ʈ���� A�� �ε���(0) ���� ������ ��
// ���� C�� H�� ����Ǿ��ִٸ�, H�� ��Ʈ���� C�� �ε���(2) ���� ������ ��

// ��Ʈ��带 ã�� ����, ���� -1�� ������ ��带 ã���� ��, 
// ���� ã�� ����� ���� -1�� ��, �ش� ����� �ε����� ����� ����
// �� ����� ��Ʈ��尡 ���� �ʴٸ�, �� ��Ʈ����� �ϳ��� �ٸ� �� ����� ��Ʈ���� �������ش�.
// ��, A-B , C-H ������ �ְ�, B,H�� UNION�Լ��� ������  A-B-H-C ������ ��
// �� ��Ȳ���� A�� C�� UNION�Լ��� ������ a�� �θ���, c�� �θ��尡 0���� ���� ������ ����Ŭ�̶�� �ǴܵǾ� �̾������ʴ´�.

#define MAX_VERTICES 50

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 100

int parent[MAX_VERTICES];			// parent�� ����Ŭ�� Ȯ�� �� ����

struct Edge 
{
	int start, end, weight;			// �ּҺ�����Ʈ���̹Ƿ�, ������ ����ġ�� �־����
};

typedef struct GraphType 
{
	int n;
	struct Edge edges[(MAX_VERTICES * (MAX_VERTICES-1))/2];		//������ ������ �ִ밳���� ���� n* (n-1) /2
}GraphType;

void set_init(int n)
{
	for (int i = 0; i < n; i++)		// parent�� -1�� �ʱ�ȭ
		parent[i] = -1;
}

int set_find(int curr)			// �Ű������� ���� ��� ���ϴ��� ��ȯ���ִ� �Լ��̴�. 
{
	if (parent[curr] == -1)
		return curr;
	while (parent[curr] != -1)
		curr = parent[curr];
	return curr;
}

void set_union(int a, int b)	// �ΰ��� ���Ұ� ���� ������ ��ģ��.
{
	int root1 = set_find(a);	// ��� a�� ��� ���ϴ���,
	int root2 = set_find(b);	// ��� b�� ��� ���ϴ���,
	if (root1 != root2)
		parent[root1] = root2;	// ���� �Ҽ��� ���� �ʴٸ�, ��� a�� ��� b�� ���ϰ� �ȴ�.
}

void graph_init(GraphType* g)
{
	g->n = 0;
	for (int i = 0; i < (MAX_VERTICES * (MAX_VERTICES - 1)) / 2; i++)
	{
		g->edges[i].start = 0;				// ����ġ�׷����� �ʱ�ȭ�ϴ� �����̴�.
		g->edges[i].end = 0;				// start�� �������� end�� ������ �̶� �����ϸ� �ǰ� weight�� ����̶� ����ȴ�.
		g->edges[i].weight = INF;
	}
}

void insert_edge_kruskal(GraphType* g, int start, int end, int w)
{
	g->edges[g->n].start = start;			// ����ġ ������ �׷����� ���Խ�Ű�� �κ��̴�.
	g->edges[g->n].end = end;
	g->edges[g->n].weight = w;
	g->n++;
}

// qsort�� ���
int compare(const void* a, const void* b)		//����Ʈ���� ����� compare �Լ�
{
	struct Edge* x = (struct Edge*)a;
	struct Edge* y = (struct Edge*)b;
	return (x->weight - y->weight);
}

void kruskal(GraphType* g)		//kruskal mst �˰����� �ð����⵵�� O(e*log(e))�� �ȴ�.(������)
{								// �ִ� e����ŭ ������ �˻��ϰ�, ����Ŭ �˻縦 �ϴµ�, ����Ŭ�˻�� ����˻��̸�,
								// �ſ� �ż��ϰ� ������. ������ �����ϴµ� �ɸ��� �ð��� ���� �ð����⵵�� �¿�ȴ�.
	int edge_accepted = 0;
	int uset, vset;
	struct Edge e;

	set_init(g->n);		//���� ������ŭ Union-find�� �ε��� �ʱ�ȭ


	qsort(g->edges, g->n, sizeof(struct Edge), compare); //�����ҹ迭, ��Ұ��� ,���ũ��, ���Լ�(��� ��������)
														//�׷��� ���� ������ ����ġ ������ ���� �� ���̴�.
														// O(e*log(e))�̴�. ���⼭ g->n�� ������ ������ �ǹ��ϹǷ�
											

	printf("ũ�罺Į �ּ� ���� Ʈ�� �˰���\n");
	int i = 0;

										// �������� while�� ���� �� �����Ƿ� O(e*log(e))�� �� 
										//while�� ��ü�� �ð����⵵ e�� ����

	while (edge_accepted < (g->n - 1)) //�ּҺ�� ����Ʈ���� ���������� ���ϸ� �����ϰԵȴ�.
	{
		e = g->edges[i];			// �׷������� i��° ������ ���ϰ�,

		uset = set_find(e.start);	// i��° ������ ���������� ��Ʈ��� ã��
		vset = set_find(e.end);		// i��° ������ �������� ��Ʈ��� ã��
									// �� i��° ������ �̾��� �ִ� �κ��� ���õ� ���̴�.

		if (uset != vset)			// ����, ������ ���������� �������� �Ҽ��� �ٸ��ٸ�,
		{
			printf("���� (%d,%d) %d ����\n", e.start, e.end, e.weight);		//���� �� ���õǾ��ٴ� ������ ����ϰ�
			edge_accepted++;		// ����Ʈ���� ���������� �ø��� -> n-1���� �� ������
			set_union(uset, vset);	// ���õ� ������ �������� set_union���� ��ġ�� uset�� vset�� �Ҽӵ� �� �̴�.
		}
		i++; //�� ��ƾ�� �������� i�� �����ش�. 
	}


}

/*
int main(void)
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	graph_init(g);

	insert_edge_kruskal(g, 0, 1, 29);
	insert_edge_kruskal(g, 1, 2, 16);
	insert_edge_kruskal(g, 2, 3, 12);
	insert_edge_kruskal(g, 3, 4, 22);
	insert_edge_kruskal(g, 4, 5, 27);
	insert_edge_kruskal(g, 5, 0, 10);
	insert_edge_kruskal(g, 6, 1, 15);
	insert_edge_kruskal(g, 6, 3, 18);
	insert_edge_kruskal(g, 6, 4, 25);
	kruskal(g);
	free(g);
	return 0;

}
*/