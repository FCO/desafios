/*
    https://leetcode.com/problems/merge-k-sorted-lists/

    Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

    Example:

    Input:
    [
      1->4->5,
      1->3->4,
      2->6
    ]
    Output: 1->1->2->3->4->4->5->6
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {

        ListNode head = null;
        ListNode tail = null;
        ListNode maxNode = new ListNode(Integer.MAX_VALUE);
        while(true) {

            ListNode smallest = maxNode;
            int smallestIdx = -1;
            for(int i  = 0; i < lists.length; i++) {
                if(lists[i] != null && lists[i].val < smallest.val) {
                    smallest = lists[i];
                    smallestIdx = i;
                }
            }

            if(smallest == maxNode) {
                break;
            }

            if(head == null) {
                head = new ListNode(smallest.val);
                tail = head;
            } else {
                tail.next = new ListNode(smallest.val);
                tail = tail.next;
            }

            lists[smallestIdx] = smallest.next;
        }

        return head;
    }
}