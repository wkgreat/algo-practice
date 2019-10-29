package wk.leetcode.t22;

import java.util.*;

/**
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 例如，给出 n = 3，生成结果为：
 *
 * [
 *   "((()))",
 *   "(()())",
 *   "(())()",
 *   "()(())",
 *   "()()()"
 * ]
 * */


/**官方答案*/
class Solution3 {
    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList();
        if (n == 0) {
            ans.add("");
        } else {
            for (int c = 0; c < n; ++c)
                for (String left: generateParenthesis(c))
                    for (String right: generateParenthesis(n-1-c))
                        ans.add("(" + left + ")" + right);
        }
        return ans;
    }
}

/**错误*/
public class Solution {

    public List<String> generateParenthesis(int n) {

        return paths(0,0,n);

    }

    public List<String> paths(int x, int y, int s) {

        List<String> thePaths = new ArrayList<>();
        if((x==0 && y==1) || (y==s && x==s-1)) {
            return thePaths;
        }
        if(x>s || y>s) {
            return thePaths;
        }
        if(x==s && y==s) {
            thePaths.add("");
            return thePaths;
        }
        else {
            List<String> xPaths = paths(x+1,y,s);
            List<String> yPaths = paths(x,y+1,s);
            for(String p : xPaths){
                thePaths.add("("+p);
            }
            for(String p : yPaths){
                thePaths.add(")"+p);
            }
            return thePaths;
        }

    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        List<String> r = solution.generateParenthesis(4);
        for(String s : r) {
            System.out.println(s);
        }
    }

}

/**错误2*/
class Solution2 {
    public List<String> generateParenthesis(int n) {

        List<String> res = new ArrayList<>();
        for(String s : gParenthesis(n)) {
            res.add(s);
        }
        return res;
    }

    public Set<String> gParenthesis(int n) {

        Set<String> res = new HashSet<>();

        if(n==0) {
            res.add("");
            return res;
        } else {
            Set<String> r = gParenthesis(n-1);
            for(String s : r) {
                res.add(s+"()");
                res.add("("+s+")");
                res.add("()"+s);
            }
            return res;
        }
    }
    public static void main(String[] args) {
        Solution2 solution = new Solution2();
        List<String> r = solution.generateParenthesis(4);
        for(String s : r) {
            System.out.println(s);
        }
    }

}
