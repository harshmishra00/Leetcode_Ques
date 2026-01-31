class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int circleInd=-1;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                circleInd=i-1;
                break;
            }
        }

        if(circleInd==-1){
            reverse(nums.begin(),nums.end());
            return;
        }

        int rightLar=circleInd;
        for(int i=n-1;i>=circleInd+1;i--){
            if(nums[i]>nums[circleInd]){
                rightLar=i;
                break;
            }
        }
        swap(nums[circleInd],nums[rightLar]);
        reverse(nums.begin()+circleInd+1, nums.end());
    }
};