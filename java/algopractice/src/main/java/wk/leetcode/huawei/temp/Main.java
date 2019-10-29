package wk.leetcode.huawei.temp;

import java.util.Scanner;

public class Main {

    public static int[] drink(int[] t) {
        int a = t[0];
        int b = t[1];
        if (b<=0) return new int[] {a,0};
        if (b<2) return new int[] {a,0};
        if (b==2) {
            return new int[] {a+1,0};
        } else {
            int newa = b / 3;
            int bb = (b % 3) + newa;
            return drink(new int[] {a + newa, bb});
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        while (in.hasNextLine()) {
            int a = Integer.parseInt(in.nextLine());
            if(a==0) {
                return;
            } else {
                int[] r = drink(new int[] {0, a});
                System.out.println(r[0]);
            }
        }
    }
}
