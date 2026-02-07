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
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        stack<int> st;
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast!=NULL && fast->next!=NULL){
            st.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }

        if(fast!=NULL){
            slow=slow->next;
        }

        while(slow!=NULL){
            if(slow->val!=st.top()){
                return false;
            }
            slow=slow->next;
            st.pop();
        }
        return true;
        
    }
};