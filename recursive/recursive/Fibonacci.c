// �Ǻ���ġ ������ ��ȯȣ�� �� ������ ������
#include <stdio.h>

int count=0;
int FibonacciRec(int n)
{
	count++;
	if (n == 0)
		return 0;
	if (n ==1)
		return 1;
	
	return FibonacciRec(n - 2) + FibonacciRec(n - 1);
}

//						n=5
//				Fib (3) + Fib (4)
//		Fib(1)+Fib(2)	Fib(2)+Fib(3)
//			.		.	.	.	.	.
//								.		.
// �ð����⵵�� O(2^n)�� ��, ���� �þ

int FibonacciFor(int n)
{
	
	if (n == 0) return 0;
	if (n <= 2) return 1;
	
	int res=0;
	int first = 1;
	int second = 1;

	for (int i=2; i < n; i++)
	{
		res = first + second;
		second = first;
		first = res;
	}

	return res;
}

/*
int main()
{
	printf("%d\n", FibonacciRec(10));
	printf("%d\n", count);
	
	count = 0;
	printf("%d\n", FibonacciFor(10));
	printf("%d", count);
	
	return 0;
}
*/