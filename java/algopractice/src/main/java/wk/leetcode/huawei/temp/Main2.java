package wk.leetcode.huawei.temp;

import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class Main2 {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        if(scanner.hasNextLine()) {
            int n = Integer.parseInt(scanner.nextLine());
        }
        Set<Integer> theSet = new TreeSet();
        while(scanner.hasNextLine()) {
            String s = scanner.nextLine();
            if(s.equals("")) return;
            int n = Integer.parseInt(s);
            theSet.add(n);
        }
        for(int a : theSet) {
            System.out.println(a);
        }
    }

}
