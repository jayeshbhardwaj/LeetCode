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
    void reorderList(ListNode* head) {
        
        
        ListNode* node = head;
        stack<ListNode*> stack;
        while(node!=NULL){
            stack.push(node);
            node = node->next;
        }
        ListNode* start = head;
        int i = 0;
        int n = stack.size();
        if(n < 3) return;
        while(i < (n+1)/2-1){
            ListNode* s = start->next;
            start->next = stack.top();
            stack.pop();
            start->next->next = s;
            stack.top()->next=NULL;
            start = s;
            i++;
        }
        
    }
};