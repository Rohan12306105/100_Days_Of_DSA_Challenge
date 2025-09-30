/*
https://leetcode.com/problems/linked-list-cycle/solutions/6556606/0ms-100-step-by-step-explained-with-visualization-easiest-to-understand-java-c-python
*/


class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                return true; // Cycle detected
            }
        }
        return false; // No cycle
    }
};