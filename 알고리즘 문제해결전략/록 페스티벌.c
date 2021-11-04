#include <stdio.h>

// 너무너무너무너무 난잡 다시 풀기
int main()
{
    int C;
    int data[1000];

    scanf("%d", &C);

    for (int i = 0; i < C; i++)
    {
        int N = 0, L = 0, temp = 0;
        double min;
        scanf("%d %d", &N, &L);

        for (int j = 0; j < N; j++)
        {
            scanf("%d", &data[j]);
            temp += data[j];
        }

        min = temp / N;
        int tmp = 0;
        while (tmp < N - L + 1)
        {
            int count = 0, sum = 0;
            for (int k = tmp; k < N; k++)
            {
                sum += data[k];
                count++;
                if (count >= L)
                {
                    double result = (double)sum / (double)count;
                    if (min > result)
                        min = result;
                }
            }
            tmp++;
        }
        printf("%.10lf \n", min);
    }
    return 0;
}