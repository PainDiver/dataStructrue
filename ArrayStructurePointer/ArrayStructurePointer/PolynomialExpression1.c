#include <stdio.h>

#define MAX(a,b) (((a)>(b))?(a):(b))		// ũ�Ⱑ �� ū ���� ����
#define MAX_DEGREE 101						// �ְ� ���� 101


// ���׽� ����ü�� �ְ����� ������ �� ������ ����� �迭�� ������ �ִ� ��
// ���׽��� ������ �����ϳ�, ��κ��� ���� ����� 0�̸� ���� ���� ����

typedef struct 
{
	int degree;						// ���׽��� �ְ�����
	float coef[MAX_DEGREE];			// �� �������� �� �����
} polynomial;


polynomial poly_add1(polynomial A, polynomial B)
{
	polynomial C;						// ���׽� C����
	int Apos = 0, Bpos = 0, Cpos = 0;	// ������ A,B ���׽��� iterator ����
	int degree_a = A.degree;			// A�� �ְ�����
	int degree_b = B.degree;			// B�� �ְ�����
	C.degree = MAX(A.degree, B.degree);	// A,B �� �� �ְ������� ���� ���� C�� �ְ������� ����
	while (Apos <= A.degree && Bpos <= B.degree)	// �� ���׽��� iterator�� �ְ������� �� ������ �����
	{
		if (degree_a > degree_b)				// ���� a�� �ְ������� b���� ���ٸ�
		{
			C.coef[Cpos++] = A.coef[Apos++];	// C�� iterator�� �ش� ������ ����� A�� ��� ����
			degree_a--;							// A�� ���� 1���� �̹� ó���� �����Ƿ� ���̳ʽ�
		}
		else if (degree_a == degree_b)			// ���� A�� B�� ������ ���� �ϴٸ�
		{
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];	// C�� iterator�� �ش� ������ �����Ͽ� A�� B�� ����� ������
			degree_a--;											// A�� ������ �ϳ� �پ�ߵ�
			degree_b--;											// B ���� ��������
		}
		else
		{											// ���� B�� A�� �������� ���� ���
			C.coef[Cpos++] = B.coef[Bpos++];		// C�� iteartor�� �ش� ������ �����Ͽ� B�� ����� ������
			degree_b--;								// B�� ������ �ٿ��� ��
		}
	}
	return C;
}


/*
int main()
{
	polynomial a = { 5,{3,6,0,0,0,10} };
	polynomial b = { 4,{7,0,5,0,1} };
	polynomial c;
	c = poly_add1(a, b);
	printf("�ְ����� :%d\n", c.degree);
	for (int i = 0; i <= c.degree; i++)
	{
		if(i!=c.degree && c.coef[i]!=0)
			printf("%.0fx^%d + ", c.coef[i],c.degree-i);
		else if(c.coef[i] !=0)
			printf("%.0f", c.coef[i]);
	}
}
*/