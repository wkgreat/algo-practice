package wk.leetcode.t41;

/**
 * @author Ke Wang
 * @since 2020/10/26
 */
public class T41 {
    public static void main(String[] args) {
        int nums[] = new int[] {1};
        Solution solution = new Solution();
        int r = solution.firstMissingPositive(nums);
        System.out.println(r);
    }
}

class Solution {
    public int firstMissingPositive(int[] nums) {
        int len = nums.length;
        if(len==0) {
            return 1;
        }
        int[] lookup = new int[len];
        for(int n : nums) {
            if(n>0 && n<len) {
                lookup[n-1] = n;
            }
        }
        int i=0;
        for(i=0; i<len; i++) {
            if(lookup[i]<=0) {
                return i+1;
            }
        }
        return i+1;
    }
}
