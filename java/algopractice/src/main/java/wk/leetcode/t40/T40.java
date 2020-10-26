package wk.leetcode.t40;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/**
 * @author Ke Wang
 * @since 2020/10/23
 * [10,1,2,7,6,1,5]
 * 8
 */
public class T40 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] candidates = new int[] {10,1,2,7,6,1,5};
        List<List<Integer>> results = solution.combinationSum2(candidates, 8);
        System.out.println(results);
    }
}

/**
 * 自己实现-实现很完美
 * */
class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        return resolve(new LinkedList(), candidates, 0, candidates.length, target);
    }
    public List<List<Integer>> resolve(List<Integer> head, int[] candidates, int left, int right, int target) {
        List<List<Integer>> results = new LinkedList();
        if(target<=0 || left>=right) {
            return results;
        }
        int p = Integer.MIN_VALUE;
        for(int i=left; i<right; ++i) {
            int a = candidates[i];
            if(a!=p) {
                p = a;
                int rest = target - a;
                if(rest<0) {
                    break;
                }
                List<Integer> res = copy(head);
                res.add(a);
                if(rest==0) {
                    results.add(res);
                } else if(rest>0) {
                    List<List<Integer>> ress = resolve(res, candidates, i+1, right, rest);
                    results.addAll(ress);
                }
            }

        }
        return results;
    }

    public List<Integer> copy(List<Integer> theList) {
        List<Integer> newList = new LinkedList();
        for(int a : theList) {
            newList.add(a);
        }
        return newList;
    }
}