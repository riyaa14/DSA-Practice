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
    
    ListNode* getMidPt(ListNode* head){
        ListNode* slow = head;
        ListNode* fast =  head;
        
        while(fast->next and fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    ListNode* reverse(ListNode* tail){
        ListNode* curr = tail;
        ListNode* prev = NULL;
        ListNode* nextNode;
        
        while(curr){
            // save the linkedList after curr
            nextNode = curr->next; 
            // set curr to prev node
            curr->next = prev;
            // move prev to curr;
            prev = curr;
            // make nextNode the curr node
            curr = nextNode;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        ListNode* midPt = getMidPt(head);
        if(midPt == head and midPt->next and midPt->val != midPt->next->val)  return false;
        ListNode* list2head = reverse(midPt->next);
        
        while(list2head){
            if(list2head->val != head->val) return false;
            list2head = list2head->next;
            head = head->next;
        }
        
        
        return true;
    }
};