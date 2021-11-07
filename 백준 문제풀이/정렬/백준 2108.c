#pragma warning(disable : 4996)
#include <stdio.h>
#include <math.h>
#define MAX 500

void bubble_sort(int *, int);

int main()
{
    int N, index, data[MAX], result;
    double sum = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &data[i]);
        sum += data[i];
    }
    bubble_sort(data, N);

    if (sum / N > 0) //반올림 만들기
        result = (int)(sum / N + 0.5);
    else
        result = (int)(sum / N - 0.5);

    printf(("%d\n"), result);
    printf("%d\n", data[N / 2]);
    printf("%d\n", data[N - 1] - data[0]);

    return 0;
}
void bubble_sort(int data[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[j] > data[j + 1])
            {
                int tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
        }
    }
}