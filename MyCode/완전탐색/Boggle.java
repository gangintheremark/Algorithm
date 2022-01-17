import java.util.*;

public class Boggle {

	static final int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
	static final int dy[] = { 1, 0, -1, -1, -1, 0, 1, 1 };
	static final char board[][] = new char[5][5];

	static boolean inRange(int x, int y) {
		return (x >= 0 && x < 5) && (y >= 0 && y < 5);
	}

	static boolean hasWord(int x, int y, String word) {
		if (!inRange(x, y)) // 범위 밖이면 false
			return false;
		if (board[x][y] != word.charAt(0)) // 위치 (x,y)에 있는 글자가 word의 첫 글자가 아니면 false
			return false;
		if (word.length() == 1)
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

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int C = s.nextInt();
		for (int c = 0; c < C; c++) {

			for (int i = 0; i < 5; i++) { // 보글 게임판 생성
				String tmp = s.next();
				for (int j = 0; j < 5; j++)
					board[i][j] = tmp.charAt(j);
			}

			int N = s.nextInt();
			String[] str = new String[N];

			for (int n = 0; n < N; n++)
				str[n] = s.next();

			for (int n = 0; n < N; n++) {
				System.out.print(str[n]);
				boolean isWord = false;
				for (int i = 0; i < 5; i++)
					for (int j = 0; j < 5; j++) {
						if (hasWord(i, j, str[n])) {
							isWord = true;
							break;
						}
						if (isWord)
							break;
					}
				if (isWord)
					System.out.println("\tYES");
				else
					System.out.println("\tNO");

			}
		}
	}

}
