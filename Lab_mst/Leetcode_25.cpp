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
    ListNode* reverse(ListNode* st, ListNode* end){
    ListNode* prev = NULL;
    ListNode* curr = st;
    while(curr != end){
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}
    ListNode* reverseKGroup(ListNode* head, int k) {
       if(head==NULL){
        return NULL;
       }
        ListNode* end = head;

        int i = 0;
        while(i < k){
            if(end == NULL){
                return head;
            }
            end = end->next;
            i++;
        }
        ListNode* newhead = reverse(head, end);
        head->next = reverseKGroup(end, k);

        return newhead;
    }
};
