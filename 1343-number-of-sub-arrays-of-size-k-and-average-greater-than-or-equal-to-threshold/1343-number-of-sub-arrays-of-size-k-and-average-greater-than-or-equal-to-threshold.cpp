class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int n=nums.size();
        int currSum=0;
        int count=0;

        for(int i=0;i<k;i++){
            currSum+=nums[i];
        }

        if(currSum/k>=threshold){
            count++;
        }

        int maxSum=currSum;

        for(int right=k;right<n;right++){
            currSum+=nums[right];
            currSum-=nums[right-k];
            if(currSum/k>=threshold){
            count++;
        }
        }
    return count;
    }
};