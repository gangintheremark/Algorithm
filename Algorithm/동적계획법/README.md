#### ������ȹ�� (Dynamic programming)

> - ��ȯ���� ���� ����ϴ� ���
> - ������ȹ���� bottom-up ����̸�, recursion�� ���ݵǴ� �ߺ������ ����.

`�Ǻ���ġ`

```c++
int fib(int n) {
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++)
		f[n] = f[n - 1] + f[n - 2];
	return f[n];
}
```

`���װ��`

n�� �� k���� �����ϴ� ����� ��

```c++
int binomial(int n, int k) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k && j <= i; j++) {
			if (k == 0 || n == k)
				binom[i][j] = 1;
			else
				binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
		}
	}
	return binom[n][k];
}
```
