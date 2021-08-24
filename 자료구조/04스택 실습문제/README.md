> - [10828 스택](https://www.acmicpc.net/problem/10828)

스택이 자주 사용하는 연산 *push pop empty size* 를 이용하여 푸는 스택의 기본적인 문제

> - [10773 제로](https://www.acmicpc.net/problem/10773)
 
최근에 들어온 수가 먼저 지워진다는 FIFO 형식으로 스택을 이용한다.

> - [9012 괄호](https://www.acmicpc.net/problem/9012)
> - [4949 균형잡인 세상](https://www.acmicpc.net/problem/4949)

스택의 대표적인 응용 문제인 괄호 검사 문제 였다. 

괄호가 올바르게 입력되었는지 검사하는 문제로 괄호를 여는 '(' '['를 스택에 push 하고 

괄호를 닫는 ')' ']' 가 나오면 스택의 top을 pop 하여 모양이 맞는지 체크한다. 

4949번 에서는 fgets를 사용하여 문자열의 공백까지 읽어들일 수 있게 하였다. 이 부분이 scanf와 차이점 ! 
```
		fgets(buffer,102, stdin);
```