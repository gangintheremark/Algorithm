#pragma warning(disable : 4996)
#include <stdio.h>

int main()
{
    int C;
    int data[1000];

    scanf("%d", &C);

    for (int i = 0; i < C; i++)
    {
        int N, L;
        double min = 100;
        scanf("%d %d", &N, &L);

        for (int j = 0; j < N; j++)
            scanf("%d", &data[j]);

        int tmp = 0;
        while (tmp <= N - L)
        {
            double count = 0, sum = 0;

            for (int k = tmp; k < N; k++)
            {
                sum += data[k];
                count++;
                if (count >= L)
                {
                    double result = sum / count;
                    if (min > result)
                        min = result;
                }
            }
            tmp++;
        }
        printf("%0.12lf \n", min);
    }
    return 0;
}