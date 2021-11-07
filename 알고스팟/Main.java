import java.util.Scanner;

/*
록 페스티벌 문제 c와 같은 코드인데 왜와이 자바는 오답이라 뜰까... ... 
공부 더 한 다음 해결해보기 ★★★
 */
public class Main {
	public static double min = Double.MAX_VALUE;
	public static Scanner s = new Scanner(System.in);

	public static void main(String[] args) {

		int C = s.nextInt();
		for (int i = 0; i < C; i++) {
			int N = s.nextInt();
			int L = s.nextInt();

			int[] date = new int[N];

			for (int j = 0; j < N; j++)
				date[j] = s.nextInt();

			int tmp = 0;
			while (tmp > N - L) {
				float sum = 0, count = 0;
				for (int k = tmp; k < N; k++) {
					sum += date[k];
					count++;

					if (count >= L) {
						float avg = sum / count;

						if (min > avg)
							min = avg;
					}
				}
				tmp++;
			}
			System.out.println(String.format("%.12f", min));
		}
	}
}
