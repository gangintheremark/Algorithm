#pragma warning (disable:4996)
#include <stdio.h>
#include <malloc.h>

char star[10000][10000];

void draw( int, int);
void erase(int, int, int);
int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			star[i][j] = '*';
		}
	}

	draw(1, N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%c", star[i][j]);
		}
		printf("\n");
	} 
	return 0;
}
void erase(int x, int y, int num)
{
	for (int i = x; i < x + num; i++)
		for (int j = y; j < y + num; j++)
			star[i][j] = ' ';
	return;
}
void draw(int num, int N)
{
	if (num > N)
		return;

	for (int i = num; i < N; i = i + num * 3)
		for (int j = num; j < N; j = j + num * 3)
			erase(i, j, num);
	draw(num * 3, N);

	
}