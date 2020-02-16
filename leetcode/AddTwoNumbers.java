/*
    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

    You may assume the two numbers do not contain any leading zero, except the number 0 itself.

    Example:

    Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
    Output: 7 -> 0 -> 8
    Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
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

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {

        ListNode head = null;
        ListNode tail = null;
        boolean add_one = false;
        while((l1 != null || l2 != null) || add_one) {

            int l1_value = l1 != null ? l1.val : 0;
            int l2_value = l2 != null ? l2.val : 0;

            int digit = l1_value + l2_value;
            if(add_one) {
                digit++;
                add_one = false;
            }

            add_one = digit > 9;
            digit = digit % 10;

            ListNode new_node = new ListNode(digit);
            if(head == null) {
                head = new_node;
                tail = new_node;
            } else {
                tail.next = new_node;
                tail = tail.next;
            }

            if(l1 != null) l1 = l1.next;
            if(l2 != null) l2 = l2.next;
        }

        return head;
    }
}