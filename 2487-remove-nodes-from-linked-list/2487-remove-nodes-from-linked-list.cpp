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
    ListNode* removeNodes(ListNode* head) {
        if (!head) return nullptr;
        ListNode* temp=head;
        vector<int> vec;
        while(temp){
            vec.push_back(temp->val);
            temp=temp->next;
        }

        int n=vec.size();
        int maxm=vec[n-1];
        vector<int> result;
        // result.push_back(max);
        for(int i=n-1;i>=0;i--){
            if(vec[i]>=maxm){
                maxm=vec[i];
                result.push_back(vec[i]);
            }
        }

        reverse(result.begin(),result.end());
        ListNode* newHead = new ListNode(result[0]);
        ListNode* curr = newHead;

        for (int i = 1; i < result.size(); i++) {
            curr->next = new ListNode(result[i]);
            curr = curr->next;
        }
        return newHead;
    }
};