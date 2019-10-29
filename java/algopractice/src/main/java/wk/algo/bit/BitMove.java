package wk.algo.bit;

/**
 * 左右位移
*/
public class BitMove {

    public static void move() {

        /**
         * n = a*2^m + ... + b*2^2 + c*2^1 + d*2^0
         * 如果n是偶数, 则多项式2^0这一项为0*2^0,相当于没有1这一项 n>>2 等价 n/2
         * 如果n是奇数, 则多项式2^0这一项为1*2^0,相当于有1这一项 n>>2 等价 (n-1)/2 
        */
        System.out.println("100 右移一位: " + (100 >> 1));
        System.out.println("15 右移一位: " + (15 >> 1)); 

        /**
         * 右移 相当于乘以2
        */
        System.out.println("100 左移一位: " + (100 << 1));
        System.out.println("15 左移一位: " + (15 << 1)); 

    }

    public static void main(String[] args) {
        move();
    }

}