/**
    https://leetcode.com/problems/linked-list-cycle-ii/description/

 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool cycleExists = false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                cycleExists = true;
                break;
            }
        }
        
        if (!cycleExists){
            return NULL;
        }

        // Floyd's algo -> distance from start point to cycle entry node 
        // and collision node to cycle entry node is equal

        ListNode* entry = head;
        while(entry != slow){
            entry = entry->next;
            slow = slow->next;
        }

        return entry;
    }
};