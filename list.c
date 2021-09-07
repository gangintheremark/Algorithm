void merge(int data[], int p, int q, int r)
{
    int i = p, j = q + 1, k = p;
    int tmp[data.length()];
    while (i <= q && j <= r)
    {
        if (data[i] <= data[j])
            tmp[k++] = data[i++];
        else
            tmp[k++] = data[j++];
    }

    while (i <= q)
        tmp[k++] = data[i++];
    while (j <= r)
        tmp[k++] = data[j++];

    for (int i = p; i < r; i++)
        data[i] = tmp[i]; // 정렬된 데이터들을 원래 배열로 옮겨주는 작업
}

void merge_sort(int A[], int p, int r)
{
    if (p < r)
    {
        q = (p + q) / 2;
        merge_sort(A, p, q);
        merge_sort(A, q + 1, r);
        merge(A, p, q, r);
    }
}