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
        // base csses for empty and one ListNode
        if(head == nullptr || head->next == nullptr || k == 0) return head;
        ListNode* temp = head;
        //find the length  and lets assume that temp is equal to  { tail}
        int length = 1;
        while(temp->next != nullptr) {
            length++;
            temp = temp->next;
        }
        //if the kth node and size of node are equal then write this 
       if(k % length == 0) return head;
        //now link the lastnode to frist node for one wrapping means rotaion
        temp->next = head;
        //if size the k is gerthan than list 
        k = k % length;  // k = 17then 7% 5 = 2 means 5 + 2 
        //to find the end of the list 
        int end = length - k;
        // do the itartion  until it reaches the 0
        while(end > 0) {
           end--;
           temp = temp->next;
        }
           //finally broke the lastnode and point to nullptr  lastnode is equal to tail
           head = temp->next;
           temp->next = nullptr;
          return head;
    }
};