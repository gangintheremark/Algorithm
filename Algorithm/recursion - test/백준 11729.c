#pragma warning (disable:4996)
#include <stdio.h>
#include <math.h>

void hanoi(int n, int from, int by, int to)
{
	if (n == 1)
		printf("%d %d\n", from, to);
	else
	{
		hanoi(n - 1, from, to, by);
		printf("%d %d\n", from, to);
		hanoi(n - 1, by, from, to);
	}
}
int main()
{
	int N;
	int count;

	scanf("%d", &N);

	count = pow(2, N) - 1;
	printf("%d\n", count);

	hanoi(N, 1, 2, 3);

	return 0;
}