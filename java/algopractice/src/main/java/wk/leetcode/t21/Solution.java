package wk.leetcode.t21;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 *
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 */

class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

class Solution {

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {

        ListNode newHead = new ListNode(-1);
        ListNode pHead = newHead;
        ListNode h1 = l1;
        ListNode h2 = l2;

        while(h1!=null || h2!=null) {
            int v1 = h1==null?Integer.MAX_VALUE:h1.val;
            int v2 = h2==null?Integer.MAX_VALUE:h2.val;
            if(v1<v2) {
                pHead.next = h1;
                pHead = pHead.next;
                h1 = h1.next;
            } else {
                pHead.next = h2;
                pHead = pHead.next;
                h2 = h2.next;
            }
        }
        return newHead.next;
    }
}
