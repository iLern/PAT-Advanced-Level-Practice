/**
 * J1065
 */
import java.math.BigInteger;
import java.util.Scanner;
public class J1065 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 1; i <= n; i++) {
            BigInteger a = sc.nextBigInteger();
            BigInteger b = sc.nextBigInteger();
            BigInteger c = sc.nextBigInteger();

            if (a.add(b).compareTo(c) > 0) {
                System.out.println(String.format("Case #%d: %s", i, "true"));
            } else {
                System.out.println(String.format("Case #%d: %s", i, "false"));
            }
        }

        sc.close();
    }
}