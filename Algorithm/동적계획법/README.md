#### 동적계획법 (Dynamic programming)

> - 순환식의 값을 계산하는 기법
> - 동적계획법은 bottom-up 방식이며, recursion에 수반되는 중복계산이 없다.

`피보나치`

```c++
int fib(int n) {
	f[1] = f[2] = 1;
	for (int i = 3; i <= n; i++)
		f[n] = f[n - 1] + f[n - 2];
	return f[n];
}
```

`이항계수`

n개 중 k개를 선택하는 경우의 수

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
