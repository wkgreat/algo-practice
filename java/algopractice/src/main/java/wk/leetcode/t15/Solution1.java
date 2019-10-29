package wk.leetcode.t15;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * {@link https://leetcode-cn.com/problems/3sum/}
 * a+b+c==0
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组。
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 满足要求的三元组集合为：
 * [
 *   [-1, 0, 1],
 *   [-1, -1, 2]
 * ]
 * */

/**
 * 最原始的思路 有问题
 * */
public class Solution1 {

    public List<List<Integer>> threeSum(int[] nums) {

        List<List<Integer>> results = new ArrayList<List<Integer>>();

        for(int i=0; i<nums.length; ++i) {
            for(int j=i+1; j<nums.length; ++j) {
                for(int k=j+1; k<nums.length; ++k) {
                    if((nums[i]+nums[j]+nums[k])==0) {
                        List<Integer> theList = new ArrayList<Integer>();
                        theList.add(nums[i]);
                        theList.add(nums[j]);
                        theList.add(nums[k]);
                        results.add(theList);
                    }
                }
            }
        }

        return results;

    }

}

/**
 *
 * */
class Solution2 {

    public List<List<Integer>> threeSum(int[] nums) {

        List<List<Integer>> results = new ArrayList<List<Integer>>();
        Arrays.sort(nums);

        for(int i=0; i<nums.length && nums[i]<=0; ++i) {
            if(i>=1 && nums[i]==nums[i-1]) continue;
            if (nums[i]>0) {
                return results;
            } else {
                for(int j=nums.length-1; j>i+1 && nums[j]>=0; --j) {
                    if(j<nums.length-1 && nums[j]==nums[j+1]) continue;
                    for(int k=i+1; k<j; ++k) {
                        int s = nums[i]+nums[j]+nums[k];
                        if(s>0) break;
                        if(k>i+1 && nums[k]==nums[k-1]) continue;
                        if(s==0) {
                            List<Integer> theList = new ArrayList<Integer>();
                            theList.add(nums[i]);
                            theList.add(nums[j]);
                            theList.add(nums[k]);
                            results.add(theList);
                        }
                    }
                }
            }
        }

        return results;

    }
}


/**
 * SUCCESS!!!
 * 见网站题解
 * */
class Solution3 {

    public List<List<Integer>> threeSum(int[] nums) {

        List<List<Integer>> results = new ArrayList<List<Integer>>();
        Arrays.sort(nums); //先排序，从小到大

        for(int i=0; i<nums.length-2 && nums[i]<=0; ++i) {
            if(i>0 && nums[i]==nums[i-1]) continue; //从左边开始取数字，跳过重复的

            int j = nums.length-1; //从最右边开始取数字
            int k = i+1; //从i的右边取数字

            while(k<j) { //k 要一直在 j 的左边
                int s = nums[i]+nums[j]+nums[k];
                if(s==0) { //和是否相等
                    List<Integer> theList = new ArrayList<Integer>();
                    theList.add(nums[i]);
                    theList.add(nums[k]);
                    theList.add(nums[j]);
                    results.add(theList);
                    k++; j--; //左右收缩
                    while (k<j && nums[k]==nums[k-1]) k++;
                    while (k<j && nums[j]==nums[j+1]) j--;

                }
                if(s<0) { //如果小了, 左边收缩
                    k++;
                    while (k<j && nums[k]==nums[k-1]) k++;
                }
                if(s>0) { //如果大了, 右边收缩
                    j--;
                    while (k<j && nums[j]==nums[j+1]) j--;
                }
            }

        }

        return results;

    }

    public static void main(String[] args) {

        int[] nums = {1,-1,-1,0};
        Solution3 solution3 = new Solution3();
        solution3.threeSum(nums);

    }

}
