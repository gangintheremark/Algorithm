#include <stdio.h>

int factorial(int N)
{
	if (N == 0)
		return 1;
	else
		return factorial(N - 1) * N;
}
int main()
{
	int N;
	scanf("%d", &N);

	printf("%d", factorial(N) );
	return 0;
}