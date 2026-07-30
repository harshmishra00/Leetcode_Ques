class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int n=nums.size();
        int lsum=0;
        int rsum=0;
        for(int i=0;i<=k-1;i++){
            lsum+=nums[i];
        }
        int maxSum=lsum;
        int rightIndex=n-1;
        for(int i=k-1;i>=0;i--){
            lsum-=nums[i];
            rsum+=nums[rightIndex];
            rightIndex--;

            maxSum=max(maxSum, lsum+rsum);
        }
        return maxSum;
    }
};