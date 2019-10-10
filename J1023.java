import java.util.Scanner;
import java.math.BigInteger;

public class J1023 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String val = sc.next();

        BigInteger a = new BigInteger(val);
        BigInteger b = a.multiply(BigInteger.valueOf(2));

        String val2 = String.valueOf(b);

        int[] num = new int[10];
        for (int i = 0, j = 0; i < val.length() && j < val2.length(); i++, j++) {
            num[val.charAt(i) - '0']++;
            num[val2.charAt(j) - '0']--;
        }

        boolean flag = true;
        for (int x : num) {
            if (x != 0) flag = false;
        }

        if (flag) System.out.println("Yes");
        else System.out.println("No");

        System.out.println(b);
        sc.close();
    }
}