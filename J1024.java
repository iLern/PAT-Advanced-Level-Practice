import java.math.BigInteger;
import java.util.Scanner;

public class J1024 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String n = sc.next();
        int k = sc.nextInt();
        
        int cnt = 0;
        while (cnt < k) {
            String tmp = new StringBuffer(n).reverse().toString();

            if (tmp.equals(n)) {
                break;
            }

            BigInteger a = new BigInteger(n);
            BigInteger b = new BigInteger(tmp);
            n = a.add(b).toString();
            cnt++;
        }

        System.out.println(n);
        System.out.println(cnt);

        sc.close();
    }
}