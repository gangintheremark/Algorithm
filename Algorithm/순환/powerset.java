/*
멱집합 
{a,b,c,d,e,f}의 모든 부분집합을 나열하려면 
  - a를 제외한 {b,c,d,e,f}의 모든 부분집합들을 나열하고
  - {b,c,d,e,f}의 모든 부분집합에 {a}를 추가한 집합들을 나열한다.
  ...

   powerset(P, S) // S의 멱집합을 구한 후 각각에 집합 P를 합집합하여 출력

   if S is an empty set
      print P;
   else 
      let t be the first element of S;
      powerset(P, S-{t});
      powerset(PU{t}, S-{t});

    recursion 함수가 두 개의 집합을 매개변수로 받도록 설계 
    include 배열을 생성하여 
    집합 S는 data[k] ... date[n-1]이고,
    집합 P는 include[i] = true, i=0...k-1 인 원소들이다.
 */

public class Powerset {

	private static char date[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	private static int n = date.length;
	private static boolean[] include = new boolean[n];

	public static void powerSet(int k) { // 트리 상의 현재 위치 표현
		if (k == n) { // 현재 위치가 리프 노드 이면 출력하고 끝낸다.
			for (int i = 0; i < n; i++)
				if (include[i])
					System.out.print(date[i] + " ");
			System.out.println();
			return;
		}
		// 그렇지 않고, 리프노드가 아닌 트리 어딘가 위치 한다면
		include[k] = false; // 트리의 왼쪽 노드 방문
		powerSet(k + 1);
		include[k] = true; // 트리의 오른쪽 노드 방문
		powerSet(k + 1);
	}
}
