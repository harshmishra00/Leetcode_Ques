class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int currSum=0;

        for(int i=0;i<k;i++){
            currSum+=nums[i];
        }

        int maxSum=currSum;

        for(int right=k;right<n;right++){
            currSum+=nums[right];
            currSum-=nums[right-k];
            maxSum=max(currSum,maxSum);
        }
        return (double)maxSum/k;
    }
};