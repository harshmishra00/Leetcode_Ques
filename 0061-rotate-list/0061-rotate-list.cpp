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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        vector<int> vec;
        ListNode* temp=head;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        }
        k%=vec.size();
        reverse(vec.begin(),vec.end());
        reverse(vec.begin(),vec.begin()+k);
        reverse(vec.begin()+k,vec.end());

        ListNode* newHead=new ListNode(vec[0]);
        ListNode* temp2=newHead;
        for(int i=1;i<vec.size();i++){
            temp2->next=new ListNode(vec[i]);
            temp2=temp2->next;
        }

        return newHead;

    }
};