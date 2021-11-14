> - 세 행렬의 곱 ABC는 두 가지 방법으로 계산가능 ( (AB)C or A(BC) )
> - 곱하는 순서에 따라 연산량 다름
> - n개의 행렬의 곱 A<sub>1</sub>A<sub>2</sub>A<sub>3</sub>...A<sub>n</sub>을 계산하는 최적의 순서는?
> - 여기서 A<sub>i</sub>는 P<sub>k-1</sub>xP<sub>k</sub> 행렬

1.순환식 세우기

if(i==j)
m[i][j] == 0;
else(i<j)
min(m[i,k] + m[k+1,j] + p<sub>i-1</sub>p<sub>k</sub>p<sub>j</sub> );

2. 동적계획법

```c++
int matrixChain(int n) {
	for (int i = 1; i <= n; i++) {
		m[i][i] = 0;
		for (int r = 1; r <= n - 1; r++) {
			for (int i = 1; i <= n - r; i++) {
				int j = i + r;
				m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];

				for (int k = i + 1; k <= j - 1; j++) {
					if(m[i][j] > m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j])
						m[i][j] = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				}
			}
		}
	}
	return m[1][n];
}
```
