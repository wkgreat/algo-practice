package wk.leetcode.t17;

import java.util.*;

public class Solution {

    Map<Character, char[]> lookup = new HashMap<>();

    public List<String> letterCombinations(String digits) {

        if(digits==null || digits.isEmpty()) {
            return new ArrayList<>(0);
        }

        lookup.put('2',"abc".toCharArray());
        lookup.put('3',"def".toCharArray());
        lookup.put('4',"ghi".toCharArray());
        lookup.put('5',"jkl".toCharArray());
        lookup.put('6',"mno".toCharArray());
        lookup.put('7',"pqrs".toCharArray());
        lookup.put('8',"tuv".toCharArray());
        lookup.put('9',"wxyz".toCharArray());
        return combines(digits);
    }

    public List<String> combines(String digits) {
        List<String> theList = new ArrayList<String>();
        if(digits==null || digits.equals("")) {
            theList.add("");
            return theList;
        }
        char head = digits.charAt(0);
        List<String> tailStrs = combines(digits.substring(1));
        for(char c : lookup.get(head)) {
            for(String s : tailStrs) {
                theList.add(c+s);
            }
        }
        return theList;
    }

}
