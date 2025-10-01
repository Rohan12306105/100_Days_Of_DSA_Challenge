/*
https://leetcode.com/problems/rotate-list/solutions/7233501/most-easiest-beats-100
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr)
            return nullptr;
        ListNode *curr = head;
        int n = 1;
        ListNode *tail = head;
        if(curr->next==nullptr)
            return head;
        while(tail->next!=nullptr){
            n++;
            tail = tail->next;
        }
        k = k % n;
        while(k!=0){
            if(curr->next->next==nullptr){    
                ListNode *temp = head;
                head = curr->next;
                head->next = temp;
                curr->next = nullptr;
                curr = head;
                k--;
            }
            else
                curr = curr->next;
        }
        return head;
    }
};