class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> vec;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                vec.push_back(i);
            }
        }
        return vec;
    }
};