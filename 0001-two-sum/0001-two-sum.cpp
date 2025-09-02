class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int, int> m;
        vector<int> vec;
        for(int i=0;i<n;i++){
            int first=nums[i];
            int sec=target-first;
            if(m.find(sec)!=m.end()){
                vec.push_back(i);
                vec.push_back(m[sec]);
                break;
            }
            m[first]=i;
        }
        return vec;
    }
};