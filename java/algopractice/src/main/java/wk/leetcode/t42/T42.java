package wk.leetcode.t42;

/**
 * @author Ke Wang
 * @since 2020/10/26
 */
public class T42 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] height = new int[]{1,2,3};
        int r = solution.trap(height);
        System.out.println(r);
    }
}

/**
 * 厉害了，自己写的
 * 执行用时：1 ms, 在所有 Java 提交中击败了99.99%的用户
 * 内存消耗：38 MB, 在所有 Java 提交中击败了95.30%的用户
 *
 * 建议看官方解法：有3中方法：动态编程法，栈方法，双指针法
 * */
class Solution {
    public int trap(int[] height) {
        return calc(height, 0, height.length-1);
    }

    public int min(int a, int b) {
        return a<b?a:b;
    }

    public int calc(int[] height, int left, int right) {
        if(left>=right-1) {
            return 0;
        }
        int leftV = height[left];
        int rightV = height[right];
        int minV = min(leftV, rightV);
        int theI=left+1, theMax=height[theI];
        int innerV = 0;
        for(int i=left+1; i<right; i++) {
            if(height[i]>theMax) {
                theI = i;
                theMax = height[i];
            }
            innerV += height[i];
        }
        int res = 0;
        if(theMax<=minV) {
            res = minV * (right-left-1) - innerV;
        } else {
            res = calc(height, left, theI) + calc(height, theI, right);
        }
        return res;
    }

}
