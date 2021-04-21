#include <stdio.h>

// ���׽� ����ü �ϳ��� Ư�� ������ �� ����� ������ �ְ�, �̸� �迭�� ������ ��Ÿ�� ��
// �޸� ������ ȿ������ �̿��� ����������, ������ ������

#define MAX_TERMS 101

typedef struct {				//����ü ���ο��� �迭�� ����, ����ü�� �迭�� ������̴�.
	float coef;
	int expon;
} terms;


char compare(int a, int b)			// a,b�� ���ؼ� �� ����� �´� ��ȣ ���
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

void attach(terms* poly, int* avai, float coef, int expon)		// ���׽� �迭�� ���ο� ����, ��� �Է�
{
	int* avail = avai;

	if (*(avail) > MAX_TERMS)
	{
		fprintf(stderr, "���� ������ �ʹ� ����\n");
		exit(1);
	}
	terms* ply = poly;

	ply[*avail].coef = coef;
	ply[(*avail)++].expon = expon;

}

void poly_add2(terms* poly, int* avai, int As, int Ae, int Bs, int Be, int* Cs, int* Ce)
{
	terms* a = poly;
	int* avail = avai;
	float tempcoef;
	*Cs = *avail;
	while ((As <= Ae) && (Bs <= Be))
	{
		switch (compare(a[As].expon, a[Bs].expon))
		{
		case '>':
			attach(a, avail, a[As].coef, a[As].expon);
			As++;
			break;

		case '=':
			tempcoef = a[As].coef + a[Bs].coef;
			if (tempcoef)
				attach(a, avail, tempcoef, a[As].expon);
			As++;
			Bs++;
			break;
		case '<':
			attach(a, avail, a[Bs].coef, a[Bs].expon);
			Bs++;
			break;
		}
	}
	for (; As <= Ae; As++)
	{
		attach(a, avail, a[As].coef, a[As].expon);
	}
	for (; Bs <= Be; Bs++)
	{
		attach(a, avail, a[Bs].coef, a[Bs].expon);
	}
	*Ce = *(avail)-1;
}

/*
int main()
{
	terms a[MAX_TERMS] = { {8,3},{7,1},{1,0},{10,3},{3,2},{1,0} };
	int avail = 6;

	int Cs, Ce;
	poly_add2(a, &avail, 0, 2, 3, 5, &Cs, &Ce);

	printf("%d,%d\n", Cs, Ce);
	for (int i = Cs; i <= Ce; i++)
		printf("%d����:%.0f ", a[i].expon, a[i].coef);
	return 0;
}
*/
