// ����׷������� ���� <u,v>�� �ִٸ� ���� u�� ���� v�� ������
// ���� �׷��� �������� ��������� �������� �����鼭 ��� ������ �����ϴ� ��,

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 50

typedef struct graphNode
{
	struct graphNode* link;
	int vertex;
}GraphNode;


typedef struct graphtype
{
	int n;
	struct graphNode* adj_list[MAX_VERTICES];
}GraphType;

typedef struct stackNode
{
	int v;
	struct stackNode* link;
}StackNode;

typedef struct stackType
{
	int size;
	struct stackNode* top;
}StackType;

void init_stack(StackType* s)
{
	s->size = 0;
	s->top = NULL;
}

void push(StackType* s, int v)
{
	StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
	if (s->size == 0)
	{
		newNode->link = NULL;
	}
	newNode->link = s->top;
	newNode->v = v;
	s->top = newNode;

	s->size++;
}

int pop(StackType* s)
{
	if (s->size == 0)
		return -1;
	int res = s->top->v;
	StackNode* temp = s->top;
	s->top = s->top->link;
	free(temp);
	s->size--;
	return res;
}


void init_listT(GraphType* g)
{
	int i = 0;
	g->n = 0;
	for (i = 0; i < MAX_VERTICES; i++)
		g->adj_list[i] = NULL;
}

void insert_vertex_listT(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES)
	{
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}

void insert_edge_listT(GraphType* g, int start, int end)	//start end �� �ε����̹Ƿ� graphtype�� n�� �ѱ�� ���� �ε����� �����Ѵٴ°�
{
	GraphNode* temp;
	if (start >= g->n || end >= g->n)
	{
		fprintf(stderr, "�׷���: ������ȣ ����");
		return;
	}
	temp = (GraphNode*)malloc(sizeof(GraphNode));
	temp->vertex = end;
	temp->link = g->adj_list[start];
	g->adj_list[start] = temp;
}

//�׷����� Ž�����δ� DFS, BFS�� �ִ�. ���� �켱 Ž��, �ʺ� �켱 Ž��

//DFS�� �ѹ������� �� �� ���� ������ ���ٰ� �� �̻� �� �� ���� �Ǹ� ������� ���ư��� ������
//�׷��Ƿ� ������ �ʿ��ϴ� (��ȯȣ��� �������� ���� ���).


int topo_sort(GraphType* g)										//���������� �ܹ���׷������� ���Ǵ°�����, ������ �������� �ʰ�
{																//�����ϴ°��� ������, ������ �°� ����ϸ� ��
	int i;
	StackType s;
	GraphNode* node;

	int* in_degree = (int*)malloc(g->n * sizeof(int));		//��� ������ ��������(������ ������ ��) ��Ÿ���� ������
	for (i = 0; i < g->n; i++)
		in_degree[i] = 0;									// ���� �ʱ�ȭ
	for (i = 0; i < g->n; i++)
	{
		GraphNode* node = g->adj_list[i];					// �׷��� i������ ��������Ʈ�� while�� ������
		while (node != NULL)								// �������ִ� ��� �������� �������� �ø���.
		{
			in_degree[node->vertex]++;						// 
			node = node->link;
		}
	}

	init_stack(&s);
	
	for (i = 0; i < g->n; i++)
	{
		if (in_degree[i] == 0)						//���� �������� ���� �����̶�� ������ �ǹǷ� ���ÿ�����
			push(&s, i);
	}
	while (s.size != 0)								//���ÿ� ���� �ִٸ�
	{
		int w;
		w = pop(&s);								//���ÿ��� �������� ���� ������ ������, �����
		printf("���� %d->", w);
		node = g->adj_list[w];						//�������� ���� ������ ��������Ʈ�� �����Ͽ�
		while (node != NULL)
		{
			int u = node->vertex;					//��������Ʈ ���� ������ �پ��� �ȴ�. (��� �տ��ִ³༮�� ������� ����)
			in_degree[u]--;

			if (in_degree[u] == 0)					//�������� ���µ� 0�� �Ǹ� ���� �׳༮�� ���ÿ� �־��ش�.
				push(&s, u);
			node = node->link;						//�ݺ�
		}
	}
	free(in_degree);
	printf("\n");
	return (i == g->n);
}

/*
void main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init_listT(g);
	
	insert_vertex_listT(g,0);
	insert_vertex_listT(g,1);
	insert_vertex_listT(g,2);
	insert_vertex_listT(g,3);
	insert_vertex_listT(g,4);
	insert_vertex_listT(g,5);

	insert_edge_listT(g,0,2);
	insert_edge_listT(g,0,3);
	insert_edge_listT(g,1,3);
	insert_edge_listT(g,1,4);
	insert_edge_listT(g,2,3);
	insert_edge_listT(g,2,5);
	insert_edge_listT(g,3,5);
	insert_edge_listT(g,4,5);
	topo_sort(g);

	free(g);
	return 0;
}

*/