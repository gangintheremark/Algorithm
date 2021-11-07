import java.util.Scanner;

/*
�� �佺Ƽ�� ���� c�� ���� �ڵ��ε� �ֿ��� �ڹٴ� �����̶� ���... ... 
���� �� �� ���� �ذ��غ��� �ڡڡ�
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
