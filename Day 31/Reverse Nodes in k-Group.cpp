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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head ->next || k<=1)
            return head;
        ListNode dum(0);
        dum.next = head;
        ListNode *pge = &dum;

        while(true){
            ListNode *kth = pge;
            for (int i = 0; i < k&&kth; i++)
            {
                kth = kth->next;
            }
            if(!kth)
                break;
            ListNode *gs = pge->next;
            ListNode *ngs = kth->next;

            ListNode *prev = ngs;
            ListNode *curr = gs;
            while(curr!=ngs){
                ListNode *tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }
            pge->next = kth;
            pge = gs;
        }
        return dummy.next;
    }
};

// with comments - explaination
/*
https://leetcode.com/problems/reverse-nodes-in-k-group/solutions/6776022/easy-c-in-place-solution-using-pointers-beats-100

https://g.co/gemini/share/5e2cde2f4fef
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // --- 1. Base Case Check ---
        // If the list is empty, has only one node, or k is 1, no reversal is needed.
        if (!head || !head->next || k <= 1) {
            return head;
        }

        // --- 2. Setup ---
        // Create a dummy node to simplify handling the head of the list.
        // The final result will be dummy.next.
        ListNode dum(0);
        dum.next = head;

        // 'pge' (previous group's end) points to the node *before* the current group starts.
        // Initially, it's the dummy node.
        ListNode *pge = &dum;

        // --- 3. Main Loop to Process Groups ---
        // This loop iterates through the list, processing one group of 'k' nodes at a time.
        while (true) {
            // --- 3a. Find the k-th node ---
            // 'kth' will be the last node of the current group.
            ListNode *kth = pge;
            // Move 'kth' pointer 'k' steps forward to find the end of the group.
            for (int i = 0; i < k && kth; i++) {
                kth = kth->next;
            }

            // --- 3b. Check if a full group exists ---
            // If 'kth' is nullptr, it means we have fewer than 'k' nodes left.
            // So, we stop and don't reverse the remaining part.
            if (!kth) {
                break;
            }

            // --- 3c. Identify Group Boundaries ---
            // 'gs' (group start) is the first node of the current group.
            ListNode *gs = pge->next;
            // 'ngs' (next group start) is the node right after the current group.
            ListNode *ngs = kth->next;

            // --- 3d. Reverse the Current Group (from 'gs' to 'kth') ---
            // This is the standard iterative linked list reversal logic.
            ListNode *prev = ngs; // The new 'next' for the original first node ('gs') will be 'ngs'.
            ListNode *curr = gs;  // Start reversing from the beginning of the group.

            while (curr != ngs) { // Reverse until we've processed the entire group.
                ListNode *tmp = curr->next; // Store the next node.
                curr->next = prev;        // Point the current node to the previous one.
                prev = curr;              // Move 'prev' forward.
                curr = tmp;               // Move 'curr' forward.
            }

            // --- 3e. Reconnect the Reversed Group to the Main List ---
            // The previous group's end ('pge') should now point to the new head of our
            // reversed group, which is 'kth'.
            pge->next = kth;

            // --- 3f. Move to the Next Group ---
            // For the *next* iteration, the 'previous group's end' will be the node that
            // was originally the start of *this* group ('gs').
            pge = gs;
        }

        // --- 4. Return Result ---
        // The dummy node's 'next' pointer now points to the new head of the fully modified list.
        return dum.next;
    }
};