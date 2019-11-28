package wk.leetcode.huawei;

import java.util.ArrayDeque;
import java.util.Queue;
import java.util.Stack;

/**
 * Leetcode T32
 * 左右括号序列，求最长合法字串的长度
 * ((()))
 * (()())
 * ()()()()
 * (()()()()
 * */

/**
 * 面试时候的解法，错误
 * */
public class Solution {

    public static void maxValidLength(String s) {

        Stack<Character> stack = new Stack<>();
        Queue<Integer> queue = new ArrayDeque<>();

        for(char c : s.toCharArray()) {
            if(c=='(') {
                stack.push(c);
                queue.add(stack.size());
            } else {
                if(stack.lastElement()=='(') {
                    queue.add(stack.size()+1);
                    stack.pop();
                    queue.add(stack.size());
                }
            }
        }

        int maxV = 0;
        Object[] array = queue.toArray();
        for(int i=0; i<array.length; ++i) {
            for(int j=i+1; j<array.length; ++j) {
                int a = (int) array[i];
                int b = (int) array[j];
                if(a-b>maxV) maxV=a-b;
            }
        }

        System.out.println(maxV);

    }

    public static void main(String[] args) {
        maxValidLength("((()))");
    }

}

/**
 * Success! 自己设计的动态规划
 *
 * State[i,j] 表示i到j形成的字串是否匹配括号规则 -1 未计算; 0 不匹配; 1 匹配
 * State[i,j] =
 *  i或j越界 -> return 0
 *  M[i,j]== 0 -> return 0 (已经计算直接返回)
 *  M[i,j]== 1 -> return 1 (已经计算直接返回)
 *  M[i,j]==-1 ->           (未计算)
 *      j<=i -> return 0    (i必须在j左边)
 *      j-1==1 ->           (i与j相邻)
 *          if(s[i]=='(' && s[j]==')') -> return 1
 *          else -> return 0
 *      j-i为偶数(串长度为奇数) -> return 0
 *      j-1为奇数(串长度为偶数) ->
 *          b1 <- s[i]=='(' && s[j]==')' && State[i+1,j-1]==1
 *          b2 <- s[i]=='(' && s[i+1]==')' && State[i+2,j]==1
 *          b3 <- s[j-1]=='(' && s[j]==')' && State[i,j-2]==1
 *          if(b1 || b2 || b3) -> return 1
 *          else -> return 0
 * */
class Solution3 {

    public static void main(String[] args) {
        maxLen(")(((((()())()()))()(()))(");
    }

    public static int maxLen(String s) {
        int len = s.length();
        int[][] matrix = new int[len][len];
        for(int i=0; i<len; ++i) {
            for(int j=i+1; j<len; ++j) {
                matrix[i][j] = -1;
            }
        }

        int maxV = 0;
        for(int i=0; i<len; ++i) {
            for(int j=i+1; j<len; ++j) {
                if(getV(s,matrix,len,i,j)==1 && j-i+1>maxV) maxV = j-i+1;
            }
        }

        System.out.print("MaxV: " + maxV);
        System.out.println("\n");

        return maxV;
    }

    public static int getV(String s, int[][] matrix, int len, int i, int j) {
        if(i<0 || i>=len || j<0 || j>=len || j<=i) { //越界 且i必须在j左边
            return 0;
        }
        if(matrix[i][j]!=-1) { //已经计算过
            return matrix[i][j];
        } else { //未计算进行计算

            if(j-1==i) { //ij相邻
                if(s.charAt(i)=='(' && s.charAt(j)==')') {
                    matrix[i][j]=1;
                    return 1;
                } else {
                    matrix[i][j]=0;
                    return 0;
                }
            } else {
                if(j-i%2==0) { // 串长度为奇数
                    matrix[i][j]=0;
                    return 0;
                } else { // 串长度为偶数
                    boolean b1 = s.charAt(i)=='(' && s.charAt(j)==')' && getV(s,matrix,len,i+1,j-1)==1;
                    boolean b2 = s.charAt(i)=='(' && s.charAt(i+1)==')' && getV(s,matrix,len,i+2,j)==1;
                    boolean b3 = s.charAt(j-1)=='(' && s.charAt(j)==')' && getV(s,matrix,len,i,j-2)==1;
                    int b = (b1 || b2 || b3)?1:0;
                    matrix[i][j] = b;
                    return b;
                }
            }
        }
    }
}

/**
 * Leetcode 32
 * */
class Solution4 {
    public static void main(String[] args) {
        System.out.println(longestValidParentheses(")(((((()())()()))()(()))("));
    }
    public static int longestValidParentheses(String s) {
        int maxans = 0;
        int dp[] = new int[s.length()];
        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == ')') {
                if (s.charAt(i - 1) == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s.charAt(i - dp[i - 1] - 1) == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = Math.max(maxans, dp[i]);
            }
        }
        return maxans;
    }
}