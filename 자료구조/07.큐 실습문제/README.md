> - [18258 큐 2](https://www.acmicpc.net/problem/18258)

큐가 자주 사용하는 연산 * push pop empty size * 를 이용하여 푸는 큐의 기본적인 문제였다.

문제의 조건이 명령의 수 N (1 ≤ N ≤ 2,000,000) 이므로 큐 생성 시 
```
	q->contents = (int*)malloc(sizeof(int) * 2000000);
```
이렇게 하여 null pointer access 런타임 오류를 수정하였다. 
