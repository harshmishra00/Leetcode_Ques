class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=0;
        int maxLen=0;
        int count=0;
        while(right<n){
            if(nums[right]==0){
                count++;
            }
            while(count>1){
                if(nums[left]==0){
                    count--;
                }
                left++;
            }
            maxLen=max(maxLen,right-left);
            right++;
        }
        return maxLen;
    }
};