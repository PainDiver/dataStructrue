#include <stdio.h>

void HanoiTower(int n,char from,char temp,char to)
{
	if(n==1)
		printf("���� 1�� %c���� %c�� �ű��\n",from,to); //	A -> C		������ ������ ��ǥ�� �̵�
	else
	{
		HanoiTower(n - 1, from, to, temp);	// (ACB) A���� B��			���� �ڱ����� �ִ� ������ temp�� ġ���� ������ �� �ְ��Ѵ�. 
		printf("���� %d�� %c���� %c�� �ű��\n", n,from, to); // A -> C	�ڱ� ������ ��ǥ ��ġ�� �̵���Ų��.
		HanoiTower(n - 1, temp, from, to); // (BAC)						�ڱ����� �־��� ������ �ڱ� ���� �̵� ��Ų��. 
	}

}
// (2^n)-1 �� �����


void HanoiTower4(int n, char from, char temp1, char temp2, char to)
{
	if (n == 1)
		printf("����1�� %c���� %c�� �ű��.\n", from, to);			// ������ ������ ��ǥ�� �̵�
	else if (n == 2)
	{
		printf("���� 1�� %c���� %c�� �ű��.\n", from, temp1);		// ���� 2 ��������, �ڱ� ���� �ִ� ������ temp�� �̵���Ų��
		printf("���� 2�� %c���� %c�� �ű��.\n", from, to);			// �ڱ�� ��ǥ�� �̵��Ѵ�.
		printf("���� 1�� %c���� %c�� �ű��.\n", temp1, to);			// �ڱ� ���� �ִ� ������ �ٽ� �ڱ� ���� �̵���Ų��.
	}
	else
	{
		HanoiTower4(n - 2, from, temp2, to, temp1);						// �����̷��� ���� �������κ��� 2ĭ �����ִ� ������ temp1���� �����δ�.
		printf("���� %d�� %c���� %c�� �ű��.\n", n - 1, from, temp2);	// �����̷��� ���� �������κ��� 1ĭ �����ִ� ������ temp2�� �����δ�.
		printf("���� %d�� %c���� %c�� �ű��.\n", n, from, to);			// �ڱ�� �̵� �����ϴ� ��ǥ�� �̵��Ѵ�.
		printf("���� %d�� %c���� %c�� �ű��.\n", n - 1, temp2,to);		// �ٷ� ���� �ִ� ������ �ڱ� ���� �ø���.
		HanoiTower4(n - 2, temp1, from, temp2, to);						// �����̷��� ���� �������κ��� 2ĭ �����ִ� ������ ��ǥ�� �����δ�. 
	}
}


/*
int main()
{
	HanoiTower(3, 'A', 'B', 'C');

	printf("��\n");

	HanoiTower4(4, 'A', 'B', 'C', 'D');

	printf("��\n");
	return 0;
}
*/