class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> s(nums.begin(), nums.end());
        ListNode dummy(0), *curr = &dummy;
        while (head) {
            if (!s.count(head->val)) {
                curr->next = head;
                curr = curr->next;
            }
            head = head->next;
        }
        curr->next = nullptr;
        return dummy.next;
    }
};
