class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
    vector<bool> res;
    int val = 0;
    for(int x : nums){
        val = ((val << 1) + x) % 5;
        res.push_back(val == 0);
    }
    return res;
}

};