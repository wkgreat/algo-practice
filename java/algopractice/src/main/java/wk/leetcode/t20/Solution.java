package wk.leetcode.t20;

import java.util.HashMap;
import java.util.Map;
import java.util.Set;
import java.util.Stack;

public class Solution {

    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        Map<Character,Character> lookup = new HashMap<>();
        lookup.put(')','(');
        lookup.put(']','[');
        lookup.put('}','{');

        Set<Character> rb = lookup.keySet();

        for(char c : s.toCharArray()) {

            if(!rb.contains(c)) {
                stack.push(c);
            } else {
                if(stack.empty() || lookup.get(c)!=stack.pop()) {
                    return false;
                }
            }
        }

        return stack.empty();
    }

    public static void main(String[] args) {
        String s = "()";
        Solution solution = new Solution();
        boolean b = solution.isValid(s);
        System.out.println(b);
    }

}
