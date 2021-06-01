// �� ������ ������ �������� ���Ḯ��Ʈ�� ǥ��
// ������ ������ ���ؼ�:
// edge�� ���� ����(dense) ��������� ���� 
// edge�� ���� ����(sparse) ��������Ʈ�� ������
// ���� ��ǻ�ʹ� �޸𸮰� �˳��ϱ� ������, ��������� ����Ͽ� ������ �� ���� ��

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

typedef struct queueNode
{
	int v;
	struct queueNode* link;
}QueueNode;

typedef struct queueType
{
	int size;
	struct queueNode* head;
	struct queueNode* tail;
}QueueType;

void init_queue(QueueType* q)
{
	q->size = 0;
	q->head = NULL;
	q->tail = NULL;
}

void enqueue(QueueType* q,int v)
{
	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->v = v;
	if (q->size == 0)
	{
		q->head = newNode;
		q->tail = newNode;
		q->head->link = NULL;
	}
	else
	{
		q->tail->link = newNode;
		q->tail = newNode;
	}
	q->size++;
}

int dequeue(QueueType* q)
{
	if (q->size == 0)
		return -1;
	int res = q->head->v;
	QueueNode* temp = q->head;
	q->head = q->head->link;
	free(temp);
	q->size--;
	return res;
}


void init_list(GraphType* g)
{
	int i = 0;
	g->n = 0;
	for (i = 0; i <MAX_VERTICES; i++)
		g->adj_list[i] = NULL;
}

void insert_vertex_list(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES)
	{
		fprintf(stderr, "�׷���: ������ ���� �ʰ�");
		return;
	}
	g->n++;
}

void insert_edge_list(GraphType* g, int start, int end)	//start end �� �ε����̹Ƿ� graphtype�� n�� �ѱ�� ���� �ε����� �����Ѵٴ°�
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

visited[MAX_VERTICES];
void dfs_list(GraphType* g, int v)		// �ð����⵵ O(n+e) ��ȯȣ�� ������ n�� + ������ ������ŭ ���ư��� �� 
{
	GraphNode* w;
	visited[v] = true;
	printf("���� %d->", v);
	for (w = g->adj_list[v]; w; w = w->link)	// for���� �� e(��������)�� ���ư� (�ڽŰ� ����� �κи� ��ȸ�ϹǷ� ���߿� ���� e(�Ѱ���)�ۿ� �ȵ�) 
		if (!visited[w->vertex])				// �� for���� e(��������)�� ����ǰ�, �ᱹ�� ��� ������ ���� �ǹǷ� n�� 
			dfs_list(g, w->vertex);				// �� O(n+e(�Ѱ���))��
}										//������ ������ �̹� ��������Ʈ�� ����Ǿ� �־, 
										//������ ������ ����� ������ for������ e�� ȣ���ϴ� ����
										//��������δ� ��� ������ �������� dfs n��, for���� ������ e���� �� ����


void bfs_list(GraphType* g, int v)		// �ð����⵵ O(n+e) ��ȯȣ�� ������ n�� + ������ ������ŭ ���ư��� ��
{
	GraphNode* w;
	QueueType q;
	init_queue(&q);
	visited[v] = true;
	printf("%d �湮-> ", v);			// ó�� ������ ����ϰ�.
	enqueue(&q, v);					// ó�� ������ ��ť�� �����Ѵ�.
	while (q.size != 0)
	{
		v = dequeue(&q);			// ������ ��ť�Ͽ� �� ���� ������ ��� ã�� ����ϰ�, �� ���������� ���������� �� ã�Ƴ����� ����
		for (w = g->adj_list[v]; w; w = w->link)	// dfs�� ���������� for���� ���ؼ��� ������ ���� ��ŭ ���ư���, �����湮�� n���̴�.
			if (!visited[w->vertex])				// �� �ð����⵵�� O(n+e)
			{
				visited[w->vertex] = true;
				printf("%d �湮->", w->vertex);
				enqueue(&q, w->vertex);
			}
	}
}


/*
void main()
{
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init_list(g);
	for (int i = 0; i < 4; i++)
		insert_vertex_list(g, i);
	insert_edge_list(g, 0, 1);
	insert_edge_list(g, 0, 2);
	insert_edge_list(g, 0, 3);
	insert_edge_list(g, 1, 2);
	insert_edge_list(g, 2, 3);

	
//	printf("���� �켱 Ž��\n");
//	dfs_list(g, 0);
//	printf("\n");
	
	printf("�ʺ� �켱 Ž��\n");
	bfs_list(g, 0);
	printf("\n");

	free(g);
}
*/