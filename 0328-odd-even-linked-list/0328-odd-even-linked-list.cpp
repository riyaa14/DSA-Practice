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
    ListNode* oddEvenList(ListNode* head) {
        
        if(!head or !head->next) return head;
        
        ListNode* oddHead = head;
        ListNode* evenHead = head->next;
        
        ListNode* oddcurr = head;
        ListNode* evencurr = evenHead;
        
        while(oddcurr->next and evencurr->next){
            
            oddcurr->next = evencurr->next;
            oddcurr = oddcurr->next;
            
            if(!oddcurr->next) 
            {
                evencurr->next = nullptr;
                break;
            }
        
            evencurr->next = oddcurr->next;
            evencurr = evencurr->next;
            
        }
        
        oddcurr->next = evenHead;
    
        return oddHead;
        
    }
};