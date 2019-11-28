package wk.bytedance;

import org.omg.PortableInterceptor.SYSTEM_EXCEPTION;

public class Q1 {

    /**
     * 判断二进制有几个1
     * */
    public static int func(int x) {
        int countx = 0;
        while(x!=0) {
            countx++;
            x = x&(x-1);
        }
        return countx;
    }

    public static void printBit() {
        for(int i=0; i<20; ++i) {
            System.out.println(String.format("%2d: %5s",i, Integer.toBinaryString(i)));
        }
    }

    public static void main(String[] args) {
        printBit();
        System.out.println(4&3);
        System.out.println(func(4));
    }

}
