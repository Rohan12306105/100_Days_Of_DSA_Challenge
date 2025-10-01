/*
https://leetcode.com/problems/reverse-linked-list-ii/solutions/2311084/java-c-tried-to-explain-every-step

class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        ListNode dummy = new ListNode(0); // created dummy node
        dummy.next = head;
        ListNode prev = dummy; // intialising prev pointer on dummy node
        
        for(int i = 0; i < left - 1; i++)
            prev = prev.next; // adjusting the prev pointer on it's actual index
        
        ListNode curr = prev.next; // curr pointer will be just after prev
        // reversing
        for(int i = 0; i < right - left; i++){
            ListNode forw = curr.next; // forw pointer will be after curr
            curr.next = forw.next;
            forw.next = prev.next;
            prev.next = forw;
        }
        return dummy.next;
    }
}
*/








/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dum = new ListNode(0);
        dum->next = head;
        ListNode *prev = dum;
        for (int i = 0; i < left-1; i++)
        {
            prev = prev->next;
        }
        ListNode *curr = prev->next;
        for (int i = 0; i < right-left; i++)
        {
            ListNode *forw = curr->next;
            curr->next = forw->next;
            forw->next = prev->next;
            prev->next = forw;
        }
        return dum->next;
    }
};