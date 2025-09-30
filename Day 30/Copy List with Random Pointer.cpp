/*
https://leetcode.com/problems/copy-list-with-random-pointer/solutions/7137326/beats-97-random-pointer-clone-bas-3-steps-done
*/




/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        //O(n) traversal;
        //step1: cloning
        Node* temp = head;
        while(temp!= NULL){
            Node* copy = new Node(temp->val);
            copy->next = temp->next; //7->13
            temp->next = copy;//7->7->13
            temp = copy->next; // temp becomes 13
        }
        //
        //step 2:copying the random link in clone nodes
        temp = head;
        while(temp!=NULL){
            if(temp->random != NULL){
            temp->next->random = temp->random->next;
            }//copy 13->random = original 13->7 here 7 is of original list so temp->random->next means 13->7->7' now its points to copy
          temp = temp->next->next;
        }
        //step 3: splitting the lists
        Node* dummy = new Node(0); //without dummy we cant restore the original list
        Node* copynode = dummy;
        temp = head;
        while(temp != NULL){
            copynode->next = temp->next;
            temp->next = temp->next->next; //restore the original list
            temp = temp->next;
            copynode = copynode->next;
        }

          return dummy->next;   //returns the copy lists head;
    }
};