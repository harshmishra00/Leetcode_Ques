class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int m=nums.size();
        for(int i=0;i<m;i++){
            nums.push_back(nums[i]);
        }
        return nums;
    }
};