`재귀호출`과 `완전탐색`

### 무한루프에 빠지지 않으려면 ?

> - 기저 사례 (base case): 적어도 하나의 recursion에 빠지지 않는 경우가 존재해야 한다.
> - recursive case : recursion을 반복하다보면 결국 base case로 수렴해야 한다.

**<중첩 반복문 대체하기>**

- 예제: n개의 원소 중 m개를 고르는 모든 조합을 찾는 알고리즘

중첩 반복문으로 구현할 수 있지만 재귀 호출은 반복문보다 간결하고 유연한 코드를 작성할 수 있다.<br>남은 원소들을 고르는 **작업**을 다음과 같은 입력들을 집합으로 정의

> - 원소들의 총 개수
> - 더 골라야 할 원소들의 개수
> - 지금까지 고른 원소들

```java
import java.util.ArrayList;

// n : 전체 원소의 수
// picked : 지금까지 고른 원소들의 번호
// toPick : 더 고를 원소의 수
public class recursionEx {

	static void pick(int n, ArrayList<Integer> picked, int toPick) {
        // 기저사례 : 더 고를 원소가 없을 때 고른 원소들을 출력
		if (toPick == 0) {
			System.out.println(picked);
			return;
		}

        // 고를 수 있는 가장 작은 번호 계산
		int smallest = picked.isEmpty() ? 0 : picked.get(picked.size() - 1);
		for (int next = smallest; next < n; next++) {
			picked.add(next);
			pick(n, new ArrayList<Integer>(picked), toPick - 1);
			picked.remove(picked.size() - 1);
		}
	}
	public static void main(String[] args) {
		ArrayList<Integer> arr = new ArrayList<Integer>();
		pick(5, arr, 2);
	}
}
```

재귀 호출을 이용하면 특정 조건을 만족하는 조합을 모두 생성하는 코드를 쉽게 작성할 수 있다. <br>
때문에 `재귀 호출`은 `완전 탐색`을 구현할 때 아주 유용한 도구!

- 예제 : [보글게임](https://algospot.com/judge/problem/read/BOGGLE)

5x5 크기의 알파벳 격자에서 상하좌우/대각선으로 인접한 칸들의 글자를 이어서 단어를 찾아내는 것이다. <br><br>
`완전 탐색`을 이용해, 단어를 찾아낼 때까지 모든 인접한 칸을 하나씩 시도해 보는 것이다. 그중 한 칸에서라도 단어를 찾을 수 있으면 성공이고, 어느 칸을 선택하더라도 답이 없다면 실패. <br> <br>
다음과 같은 형태의 함수를 작성한다.
<br>
hasWord(y,x,word) = 보글 게임판의 (y,x)에서 시작하는 단어 word의 존재 여부 반환

> 기저 사례
>
> - 위치 (y,x)가 위치에서 벗어났을 경우 항상 false
> - 위치 (y,x)에 있는 글자가 원하는 단어의 첫 글자가 아닌 경우 항상 false
> - (1번 경우에 해당하지 않을 때)원하는 단어가 한 글자인 경우 항상 true

```java
	static boolean hasWord(int x, int y, String word) {
		if (!inRange(x, y)) // 범위 밖이면 false
			return false;
		if (board[x][y] != word.charAt(0)) // 위치 (x,y)에 있는 글자가 word의 첫 글자가 아니면 false
			return false;
		if (word.length() == 1) // 원하는 단어가 한 글자인 경우 true
			return true;

		// 8 칸 검사
		for (int i = 0; i < 8; i++) {
			int nextX = x + dx[i];
			int nextY = y + dy[i];
			if (hasWord(nextX, nextY, word.substring(1)))
				return true;
		}
		return false;
	}

```

`완전 탐색` 레시피

1. 완전 탐색은 존재하는 모든 답을 하나씩 검사하여 걸리는 시간은 가능한 답의 수에 정확히 비례.
2. 가능한 모든 답의 후보를 만드는 과정을 나눔
3. 그중 하나의 조각을 선택해 답의 일부를 만들고, 나머지 답을 재귀 호출을 통해 완성
