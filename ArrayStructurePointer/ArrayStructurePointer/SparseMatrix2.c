#include <stdio.h>
#define ROWS 3
#define COLS 3
#define MAX_TERMS 10

typedef struct 
{
	int row, col, value;
}element;

typedef struct SparseMatrix 
{
	element data[MAX_TERMS];
	int rows;
	int cols;
	int terms;
}SparseMatrix;

SparseMatrix sparse_matrix_add2(SparseMatrix a, SparseMatrix b)
{
	SparseMatrix c;
	int ca = 0;		//a�� ���� �� �� (�ְ����׺��� Ŀ���� ����)
	int cb = 0;		//b�� ���� �� ��
	int cc = 0;
	if (a.rows != b.rows || a.cols != b.cols)
	{
		fprintf(stderr, "��� �ط� ũ�⿡��\n");
		exit(1);
	}
	c.rows = a.rows;
	c.cols = a.cols;
	c.terms = 0;

	while (ca < a.terms && cb < b.terms) //a�� b�� ���� �� ���� �� a,b�� ���� �������� Ŀ���� ��
	{
		int inda = a.data[ca].row * a.cols + a.data[ca].col; //		  0,1,2 ����� �̷� ������ �ε���ȭ �� ��,
															//		  3,4,5 �׷��� row�� �ε����� col ������ ������ ��,
															//		  6,7,8 ���������� col �ε����� ������ 
															//		  ex) [1][1]�� �ε�����ġ�� 4�� �ش��ϴ� ��
		int indb = b.data[cb].row * b.cols + b.data[cb].col;
		if (inda < indb)	// ��Ŀ��� ������ �ε����� ����, ���� a�� �ε����� �������� ��
		{
			c.data[cc++] = a.data[ca++];		//�ε����� ���������� �κ��� ��°�� ������
		}
		else if (inda == indb)	// a,b �ε����� ���� ��
		{
			c.data[cc].row = a.data[ca].row;	// ������ a�� b�� ���� ���� value�� �־�� �ϹǷ� ��°�� ī�Ǵ� �Ұ���
			c.data[cc].col = a.data[ca].col;	// c ����� row,col�� �־��ְ�
			c.data[cc++].value = a.data[ca++].value + b.data[cb++].value; // c����� ���� a,b����� �������� �־���
		}
		else
		{
			c.data[cc++] = b.data[cb++]; 
		}
	}

	for (; ca < a.terms; ca++)		//���� ������  b�� ���� ��� ���� ���ؼ� ī�ǰ� �����ٸ� a�� ��������
	{
		c.data[cc++] = a.data[ca++];	// a ����� c����� ���� �ε����� �� �־���
	}
	for (; cb < b.terms; cb++)		// ���� ������ a�� ���� ��� ���� ���ؼ� ī�ǰ� �����ٸ� b�� ��������
	{
		c.data[cc++] = b.data[cb++];	// b����� c����� ���� �ε����� �� �־���
	}
	c.terms = cc;					//��� ������ ������ ���� cc�� ����Ű�� �ִ� �ε����� c����� ���� ��
	return c;
}


/*
int main()
{
	SparseMatrix m1 = { { {1,1,5}, {1,2,7} ,{2,0,13} ,{2,2,9} }, 3,3,4 }; // �ε��� ���� �´� ���, ��, ��, ���� ��
	SparseMatrix m2 = { {{0,0,5} ,{2,2,9}},3,3,2 }; 
	SparseMatrix m3;
	m3 = sparse_matrix_add2(m1, m2);
	
	for (int i = 0; i < m3.terms; i++)
		printf("[%d][%d] %d\n",m3.data[i].row,m3.data[i].col ,m3.data[i].value);

}
*/