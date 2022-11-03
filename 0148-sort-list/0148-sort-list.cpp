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
    
    ListNode* getMidPoint(ListNode* head){
        
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        
        while(fast and fast->next){
            prev = slow;
            fast = fast->next->next;
            slow = slow->next;

        }
        
        return prev;
    }
    
    ListNode* mergeLists(ListNode* l1, ListNode* l2){
        
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* newhead = nullptr;
        if(l1->val < l2->val){
            newhead = l1;
            l1 = l1->next;
        }else{
            newhead = l2;
            l2 = l2->next;
        }
        
        ListNode* curr = newhead;
        
        while(l1 and l2){
            
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
                
            }else{
                curr->next = l2;
                l2 = l2->next;
            }  
            
            curr = curr->next;
        }
        
        if(l1) curr->next = l1;
        if(l2) curr->next = l2;
        
         return newhead;
    
        
//         if(l1){
//         prev->next = l1;
//             l1 = l1->next;
//         } 
        
//         if(l2) {
//             prev->next = l2;
//             l2 = l2->next;
//         }
        
//         ListNode *ptr = new ListNode(0);
//         ListNode *curr = ptr;
        
//         while(l1 != NULL && l2 != NULL)
//         {
//             if(l1->val <= l2->val)
//             {
//                 curr -> next = l1;
//                 l1 = l1 -> next;
//             }
//             else
//             {
//                 curr -> next = l2;
//                 l2 = l2 -> next;
//             }
        
//         curr = curr ->next;
        
//         }
        
//          if(l1 != NULL)
//         {
//             curr -> next = l1;
//             l1 = l1->next;
//         }
        
//         if(l2 != NULL)
//         {
//             curr -> next = l2;
//             l2 = l2 ->next;
//         }
        
//         return ptr->next;
        
    }
    
    ListNode* sortList(ListNode* head) {
        
        if(!head or !head->next) return head;
        
        // Get mid point
        ListNode* mid = getMidPoint(head);
        ListNode* head2 = mid->next;
        mid->next = nullptr;
        
        // Sort left side and right side
        ListNode* list1 = sortList(head);
        ListNode* list2 = sortList(head2);
        
        // merge the 2 sorted lists  
        
        return mergeLists(list1, list2);
    }
};