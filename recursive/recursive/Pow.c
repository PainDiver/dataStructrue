// �ŵ������� ��ȯ���� ����� �� ȿ�����̴�
#include <stdio.h>

double SlowPower(double x, int n)
{
	int i;
	double res = 1.0;
	for (int i = 0; i < n; i++)
	{
		res *= x;
	}
	return res;
}
// for������ �����ϹǷ� O(n)�� �ð����⵵�� ����

double FastPower(double x, int n)
{
	if (n == 0)
		return 1;

	if (n % 2 == 0)
		return FastPower(x*x,n/2);
	else
		return x*FastPower(x*x,(n-1)/2);
	
}
// Ƚ���� �ݾ� �پ��� ������ O(logn)�� �ð����⵵�� �����Ե�


/*
int main()
{
	printf("%f\n", SlowPower(5,3));
	printf("%f\n", FastPower(5, 3));
	return 0;
}
*/