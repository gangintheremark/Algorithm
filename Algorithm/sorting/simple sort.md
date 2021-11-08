## 정렬 알고리즘

### bubble sort

```c++
void bubble_sort(int list[], int n)
{
    for (int i = n - 1; i > 0; i++) {
        for (int j = 0; j < i; j++) {
            if (list[j] < list[j + 1])
                SWAP(list[j], list[j + 1]);
        }
    }
}
```

시간복잡도 T(n) = (n-1) + (n-2) + ... + 2 + 1 = O(n<sup>2</sup>)

### selection sort

```c++
void selection_sort(int list[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int least = i;
        for (int j = i + 1; j < n; j++) {
            if (list[j] < list[least])
                least = j;
        }
        if (i != least)
            SWAP(list[i], list[least]);
    }
}
```

시간복잡도 T(n) = (n-1) + (n-2) + ... + 2 + 1 = O(n<sup>2</sup>)

### Insertion sort

```c++
void insertion_sort(int list[], int n)
{
    int i, j, key;
    for (i = 1; i < n; i++)
    {
        key = list[i];

        for (j = i - 1; j >= 0 && list[j] > key; j--)
            list[j + 1] = list[j];

        list[j + 1] = key;
    }
}
```

시간복잡도 T(n) = (n-1) + (n-2) + ... + 2 + 1 = O(n<sup>2</sup>)
