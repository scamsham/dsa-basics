public /**
        * Definition for singly-linked list.
        * public class ListNode {
        * int val;
        * ListNode next;
        * ListNode() {}
        * ListNode(int val) { this.val = val; }
        * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
        * }
        */
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode current = head, prev = null;

        while (current != null) {
            ListNode nextNode = current.next;
            current.next = prev;
            prev = current;
            current = nextNode;
        }

        return prev;
    }
}

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode() {}
 * ListNode(int val) { this.val = val; }
 * ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseListHelper(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode nextHead = reverseListHelper(head.next);
        head.next.next = head;
        head.next = null;

        return nextHead;
    }

    public ListNode reverseList(ListNode head) {
        return reverseListHelper(head);
    }
}