#pragma warning(disable : 4996)
#include <stdio.h>
#define MAX 1000000

void merge(int *, int, int, int);
void merge_sort(int *, int, int);

int main()
{
    int N, index, data[MAX];

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &index);
        data[i] = index;
    }

    merge_sort(data, 0, N - 1);

    for (int i = 0; i < N; i++)
        printf("%d\n", data[i]);
}

void merge(int data[], int left, int mid, int right)
{
    int i = left, j = mid + 1, k = left;
    int tmp[MAX];

    while (i <= mid && j <= right)
    {
        if (data[i] < data[j])
            tmp[k++] = data[i++];
        else
            tmp[k++] = data[j++];
    }
    while (i <= mid)
        tmp[k++] = data[i++];
    while (j <= right)
        tmp[k++] = data[j++];

    for (int i = left; i <= right; i++)
        data[i] = tmp[i];
}

void merge_sort(int data[], int left, int right)
{
    int mid = (left + right) / 2;

    if (left < right)
    {
        merge_sort(data, left, mid);
        merge_sort(data, mid + 1, right);
        merge(data, left, mid, right);
    }
}