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
