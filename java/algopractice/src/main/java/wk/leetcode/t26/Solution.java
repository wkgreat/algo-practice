package wk.leetcode.t26;

/**
 * 正确解答 使用双指针的方法
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/solution/shan-chu-pai-xu-shu-zu-zhong-de-zhong-fu-xiang-by-/
 * */
public class Solution {

    public int removeDuplicates(int[] nums) {
        if(nums==null) return 0;
        if(nums.length<=1) return nums.length;
        int i=0, j=1;
        for(; j<nums.length;++j) {
            if(nums[i]!=nums[j]) {
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i+1;
    }

}

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int r = solution.removeDuplicates(new int[]{1,1,2,2});
        System.out.println(r);
    }
}
