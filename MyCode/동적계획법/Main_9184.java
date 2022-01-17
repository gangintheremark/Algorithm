import java.util.Scanner;

/* 9184번 */
public class Main_9184 {
	static Scanner s = new Scanner(System.in);
	static int dp[][][] = new int[21][21][21];

	public static int w(int a, int b, int c) {
		if (bound(a, b, c) && dp[a][b][c] != 0)
			return dp[a][b][c];

		if (a <= 0 || b <= 0 || c <= 0)
			return 1;
		else if (a > 20 || b > 20 || c > 20)
			return dp[20][20][20] = w(20, 20, 20);
		else if (a < b && b < c)
			return dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

		return dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

	}

	static boolean bound(int a, int b, int c) { // 범위 체크
		return a >= 0 && b >= 0 && c >= 0 && a <= 20 && b <= 20 && c <= 20;
	}

	public static void main(String[] args) {

		while (true) {
			int a = s.nextInt();
			int b = s.nextInt();
			int c = s.nextInt();

			if (a == -1 && b == -1 && c == -1)
				break;
			System.out.printf("w(%d, %d, %d) = %d \n", a, b, c, w(a, b, c));
		}
	}
}