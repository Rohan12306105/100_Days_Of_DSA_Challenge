/*

https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/solutions/6801800/beats-100-easiest-explanation-for-beginners-java-python-c-javascript
*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* prev = dummy;
        ListNode* cur = head;

        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                while (cur->next && cur->val == cur->next->val) { // agar duplicates milte h toh prev->next ke final duplicate ke next pe point krdo simple 
                    cur = cur->next;
                }
                prev->next = cur->next; // Skip all duplicates
            } else {
                prev = prev->next; // Move to next unique node
            }
            cur = cur->next;
        }

        return dummy->next;
    }
};