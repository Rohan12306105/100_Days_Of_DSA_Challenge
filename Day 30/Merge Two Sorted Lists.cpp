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

 /*
 https://leetcode.com/problems/merge-two-sorted-lists/solutions/6507849/simple-approach-all-language-codes-beats-100
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *c1 = list1;
        ListNode *c2 = list2;
        ListNode *dum = new ListNode(-1);
        ListNode *temp = dum;
        while(c1&&c2){
            if(c1->val<c2->val){
                temp->next = c1;
                temp = c1;
                c1 = c1->next;
            }
            else{
                temp->next = c2;
                temp = c2;
                c2 = c2->next;
            }
        }
        if(c1) temp->next = c1;
        if(c2) temp->next = c2;
        return dum->next;
    }
};