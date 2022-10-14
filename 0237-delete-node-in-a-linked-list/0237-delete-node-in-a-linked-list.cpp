/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        
        node->val = node->next->val;
        
        ListNode* prev = node;
        ListNode* nodeToBeDeleted = node->next;
        
        prev->next = nodeToBeDeleted->next;
        
    }
};