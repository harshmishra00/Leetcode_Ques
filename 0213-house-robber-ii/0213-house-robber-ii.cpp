class Solution {
public:
    int steal(vector<int>& nums, int left, int right){
        int n=right-left+1;

        vector<int>dp(n+1);
        dp[0]=0;
        dp[1]=nums[left];

        for(int i=2;i<=n;i++){
            dp[i]=max(dp[i-1],nums[left+i-1]+dp[i-2]);
        }

        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(nums.size()==1) return nums[0];
        int left=steal(nums,1,n-1);
        int right=steal(nums,0,n-2);
        return max(left,right);
    }
};