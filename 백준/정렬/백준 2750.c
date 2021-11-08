#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
    int N, data[1000], index;
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &index);
        data[i] = index;
    }

    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[i] < data[j])
            {
                int tmp = data[i];
                data[i] = data[j];
                data[j] = tmp;
            }
        }
    }

    for (int i = 0; i < N; i++)
        printf("%d\n", data[i]);

    return 0;
}