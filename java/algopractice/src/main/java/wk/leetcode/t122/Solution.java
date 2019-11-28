package wk.leetcode.t122;

/**
 * 成功 贪心法
 * */
public class Solution {
    public int maxProfit(int[] prices) {
        if(prices.length==0) return 0;
        int sum = 0;
        for(int i=1; i<prices.length; ++i) {
            int p = prices[i]-prices[i-1];
            if(p>0) {
                sum+=p;
            }
        }
        return sum;
    }
}

/** 成功 动态规划解法 */
class Solution2 {
    public int maxProfit(int[] prices) {
        int len = prices.length;
        if(len < 2) return 0;
        int[][] s = new int[len][2];
        s[0][0] = 0;
        s[0][1] = 0 - prices[0];
        for(int i=1; i<len; ++i) {
            s[i][0] = Math.max(s[i-1][0],s[i-1][1]+prices[i]);
            s[i][1] = Math.max(s[i][0]-prices[i],s[i-1][1]);
        }
        return s[len-1][0];
    }
}

class Main {
    public static void main(String[] args) {
        Solution2 s = new Solution2();
        int r = s.maxProfit(new int[]{1,2,3,4,5});
        System.out.println(r);
    }
}
