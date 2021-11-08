import java.util.Scanner;

public class Main_1003 {
    static Scanner s = new Scanner(System.in);

    public static void main(String[] args) {

        int T = s.nextInt();
        int[] data = new int[41];
        data[0] = 0;
        data[1] = data[2] = 1;
        for (int i = 3; i < 41; i++)
            data[i] = data[i - 1] + data[i - 2];

        for (int i = 0; i < T; i++) {
            int N = s.nextInt();

            if (N == 0) {
                System.out.println("1 0");
            } else if (N == 1) {
                System.out.println("0 1");
            } else
                System.out.println(data[N - 1] + " " + data[N]);
        }
    }
}
