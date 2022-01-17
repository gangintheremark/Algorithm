> - [보글 게임](https://algospot.com/judge/problem/read/BOGGLE)

처음 구현했을 때, 시작위치 (x,y) 를 이중 for문으로 0부터 5까지 반복하며 hasWord 함수를 호출하고 hasWord가 true일 경우,바로 "YES"출력 후 break;하였지만 이렇게 되면 바깥 for문이 계속 실행되어서 시간이 오래 걸리는 점이 있었다. 그래서 바깥 쪽도 break; 시켜주기 위해 boolean 형 변수 isWord를 추가하였다. 시간 줄이기 위한 좋은 방법인것 같아서 메모메모
