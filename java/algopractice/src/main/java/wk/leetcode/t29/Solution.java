package wk.leetcode.t29;

import java.lang.Math;

/**
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 
 * !注意：Math.abs(-2147483648) = -2147483648
*/

/**
 * Failed..
*/
public class Solution {

    public int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        int r = 0, sum=0;
        boolean sign = (dividend>0) ^ (divisor>0); //布尔值进行异或
        dividend = dividend>0?-dividend:dividend;
        divisor = divisor>0?-divisor:divisor;
        while(sum>=dividend) {
            if(sum==dividend) return sign?-r:r;
            r++;
            sum+=divisor;
        }
        return sign?1-r:r-1;
    }

    /**
     * 一些特殊值
    */
    public void someSpecialValue() {
        System.out.println("MIN: " + Integer.MIN_VALUE);
        System.out.println("MAX: " + Integer.MAX_VALUE);
        System.out.println("1<<31 = " + (1<<31));
        System.out.println("~(1<<31) = " + (~(1<<31)));
        System.out.println("-(1<<31) = " + (-(1<<31)));
        System.out.println("(1<<31)-1 = " + ((1<<31)-1));
    }

    public static void main(String[] args) {
        // System.out.println(Math.abs(-2147483648));
        // int a = new Solution().divide(-2147483648, -1);
        // System.out.println(a);
    }

}