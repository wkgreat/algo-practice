package wk.leetcode.t19;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 *
 *
 */

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

/**
 * 正确答案
 * 技巧：在链表头部加一个哑节点，以处理链表长度为1的情况
 * */
public class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {

        ListNode pHead = new ListNode(0);
        pHead.next = head;

        ListNode pp=pHead, pn = pHead;
        for(int i=0;i<n;++i) {
            pn = pn.next;
            if(pn==null) {
                return null;
            }
        }

        while(pn.next!=null) {
            pn = pn.next;
            pp = pp.next;
        }
        pp.next = pp.next.next;
        return pHead.next;

    }
}
