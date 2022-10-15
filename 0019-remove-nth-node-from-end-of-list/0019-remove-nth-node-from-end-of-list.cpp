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
        
        // APPROACH 1 
        
//         ListNode* tail = head;
//         int totalNodes = 0;
//         while(tail){
//             tail = tail->next;
//             totalNodes++;
//         }
        
//         int k = totalNodes - n; 
        
//         if(k == 0) return head->next;
        
//         ListNode* curr = head;
//         ListNode* prev = nullptr;
        
//         while(k--){
//            curr = curr->next;
//            if(!prev) prev = head;
//            else prev = prev->next;
//         }
        
//         prev->next = curr->next;
        
        // APPROACH 2 - ONE PASS
        
        ListNode* slow = head;
        ListNode* prev = nullptr;
        ListNode* fast = head;
        
        while(n--){
            fast = fast->next;
        }
        
        while(fast){
            if(!prev) prev = head;
            else prev = prev->next;
            slow = slow->next;
            fast = fast->next;
        }
        
        if(!prev) return head->next; // this means the node to be deleted is the head node
        prev->next = slow->next;
        
        return head;
        
    }
};