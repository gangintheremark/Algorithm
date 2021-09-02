/*
cols[i] = j 는 말이 (i행, j열) 에 놓였음을 의미

int[] cols = new int[N+1];

boolean queens(int level) {   // 성공이냐 실패냐! 
  if (!promising(level)))     // 꽝
    return false;
  else if success             // 모든 말이 충돌없이 놓였다. 성공! 
    report answer and return;
  else
    visit children recursively;
}
*/
public class NqueensProblem {
	private final static int N=8;
	private static int[] cols = new int[N+1];
	
	public static void main(String[] args) {
		queens(0);
	}
	
	private static boolean queens(int level) {
		if(!promising(level))
			return false;
		else if(level == N) {
			for(int i=1;i<=N;i++)
				System.out.println("("+i+", "+cols[i]+")");
			return true;
		}
		for(int i=1;i<=N;i++) {
			cols[level+1] = i;
			if(queens(level+1))
				return true;
		}
		return false;
	}
	private static boolean promising(int level) {
		for(int i=1;i<level;i++) {
			if(cols[i] == cols[level])
				return false;
			else if((level-i) == Math.abs(cols[level] - cols[i]))  // 대각선 확인
				return false;
		}
		return true;
	}
}
