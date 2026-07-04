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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;

        ListNode* prev=dummy;
        while(prev->next!=NULL && prev->next->next!=NULL){
            ListNode* first=prev->next;
            ListNode* sec=first->next;

            first->next=sec->next;
            prev->next=sec;
            sec->next=first;

            prev=prev->next->next;
        }
        return dummy->next;
    }
};