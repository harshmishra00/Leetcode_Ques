class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>vec;
        int sum=0;
        for(int val:nums){
            sum+=val;
            vec.push_back(sum);
        }
        return vec;
    }
};
