class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int curr=0;
        int maxm=0;
        for(int val:nums){
            if(val==1){
                curr++;
                maxm=max(maxm,curr);
            }else{
                curr=0;
            }
        }
        return maxm;
    }
};