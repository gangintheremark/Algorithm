> - [10845 큐](https://www.acmicpc.net/problem/10845)
> - [18258 큐 2](https://www.acmicpc.net/problem/18258)

큐가 자주 사용하는 연산 * push pop empty size * 를 이용하여 푸는 큐의 기본적인 문제였다.

18258 큐2 같은 경우,  
문제의 조건이 명령의 수 N (1 ≤ N ≤ 2,000,000) 이므로 큐 생성 시 
```
	q->contents = (int*)malloc(sizeof(int) * 2000000);
```
이렇게 하여 null pointer access 런타임 오류를 수정하였다. 

> - [2164 카드2](https://www.acmicpc.net/problem/2164)
> - [11866 요세푸스 문제](https://www.acmicpc.net/problem/11866)

이 두 문제는 규칙에 맞춰 제거하거나 리스트의 뒤로 보내는 문제이므로

큐를 생성하여 제거할 땐 dequeue, 뒤로 보낼 땐 rear을 증가하여 contents 배열에 넣는 방식을 이용하여 풀었다.

문제는 쉽게 풀었지만 런타임 오류가 계속 떴는데 위 큐 2 문제와 같이 큐 생성 시 조건에 맞게 메모리 할당하는게 중요하였다. 