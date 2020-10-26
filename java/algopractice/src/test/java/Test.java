import java.util.ArrayList;
import java.util.List;

/**
 * @author Ke Wang
 * @since 2020/10/22
 */
public class Test {
    public static void main(String[] args) {

    }
}

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> res = new ArrayList();
        for(int c : candidates) {
            List<Integer> rs = new ArrayList();
            rs.add(c);
            res.add(rs);
        }
        return resovle(res, candidates, target);
    }

    public List<List<Integer>> resovle(List<List<Integer>> res, int[] candidates, int target) {
        List<List<Integer>> closeRes = new ArrayList();
        for(List<Integer> r : res) {
            int sum=0;
            for(int a : r) {
                sum += a;
            }
            if(sum<target) {
                //openRes.add(r);
                List<List<Integer>> newRes = new ArrayList();
                for(int c : candidates) {
                    List<Integer> newR = new ArrayList();
                    for(int a : r) {
                        newR.add(a);
                    }
                    newRes.add(newR);
                }
                newRes = resovle(newRes, candidates, target);
                closeRes.addAll(newRes);
            } else if (sum==target) {
                closeRes.add(r);
            }
        }
        return closeRes;
    }
}
