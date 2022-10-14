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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        if(!head->next or !head) return nullptr;
        
        ListNode* tail = head;
        int totalNodes = 0;
        while(tail){
            tail = tail->next;
            totalNodes++;
        }
        
        int k = totalNodes - n; 
        
        if(k == 0) return head->next;
        
        ListNode* curr = head;
        ListNode* prev = nullptr;
        
        while(k--){
           curr = curr->next;
           if(!prev) prev = head;
           else prev = prev->next;
        }
        
        prev->next = curr->next;
        
        return head;
        
    }
};