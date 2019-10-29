package wk.leetcode.t16;

import java.util.Arrays;

/**
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
 * 使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 *
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * [-4,-1, 1, 2]
 *
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 *
 * */
public class Solution {

    public int threeSumClosest(int[] nums, int target) {

        int minV = Integer.MAX_VALUE;
        int r = 0;
        int a=0,b=0,c=0;

        for(int i=0; i<nums.length; ++i) {
            for(int j=i+1; j<nums.length; ++j) {
                for(int k=j+1; k<nums.length; ++k) {
                    int s = nums[i]+nums[j]+nums[k];
                    int d = s - target;
                    int v = Math.abs(d);
                    if(v < minV) {
                        r = s;
                        minV = v;
                    }
                }
            }
        }
        return r;

    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums = {-1,2,1,-4};
        int target = 1;
        int r = solution.threeSumClosest(nums,target);
        System.out.println(r);

    }

}

/**
 * 网上答案 双指针
 * */
class Solution2 {
    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int ans = nums[0] + nums[1] + nums[2];
        for(int i=0;i<nums.length;i++) {
            int start = i+1, end = nums.length - 1;
            while(start < end) {
                int sum = nums[start] + nums[end] + nums[i];
                if(Math.abs(target - sum) < Math.abs(target - ans))
                    ans = sum;
                if(sum > target)
                    end--;
                else if(sum < target)
                    start++;
                else
                    return ans;
            }
        }
        return ans;
    }
}
