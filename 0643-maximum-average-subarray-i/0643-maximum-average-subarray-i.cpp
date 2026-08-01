class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0.0;
        int n=nums.size();
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }

        double maxAvg=sum/k;
        int left=0;
        int right=k;
        while(right<n){
            sum+=nums[right];
            sum-=nums[left];
            maxAvg=max(maxAvg,sum/k);
            left++;
            right++;
        }
        return maxAvg;
    }
};