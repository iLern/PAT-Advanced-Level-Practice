import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Date;
import java.util.List;
import java.util.Scanner;

class People implements Comparable {
    public String id;
    public Date begin, end;

    public People(String info) throws Exception {
        String[] attr = info.split(" ");

        SimpleDateFormat format = new SimpleDateFormat("HH:mm:ss");

        this.id = attr[0];
        this.begin = format.parse(attr[1]);
        this.end = format.parse(attr[2]);
    }

    @Override
    public int compareTo(Object o) {
        People p = (People)o;
        return begin.before(p.begin) ? -1 : 1;
    }

    @Override
    public String toString() {
        return this.id + " " + begin.toString() + " " + end.toString();
    }
}

public class J1006 {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);

        List<People> l = new ArrayList<>();

        int n = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            String s = sc.nextLine();
            
            l.add(new People(s));
        }

        Collections.sort(l);
        
        Date last = l.get(0).end;
        String ans = l.get(0).id;
        for (People p : l) {
            if (p.end.after(last)) {
                last = p.end;
                ans = p.id;
            }
        }

        System.out.println(l.get(0).id + " " + ans);
        sc.close();
    }
}
