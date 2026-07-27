class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxm = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            for(int j = i + 1; j < nums.size(); j++) {
                maxm = max(maxm, (nums[i]-1) * (nums[j]-1));
            }
        }
        return maxm;
    }
};
