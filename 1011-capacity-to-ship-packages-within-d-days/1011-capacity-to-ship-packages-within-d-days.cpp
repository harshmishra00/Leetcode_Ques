class Solution {
public:
    bool isValid(vector<int>& nums, int mid, int days){
        int n=nums.size();int sum=0;
        int day=1;
        for(int i=0;i<n;i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }else{
                day++;
                sum=nums[i];
            }
        }
        return day<=days;
    }
    int shipWithinDays(vector<int>& nums, int days) {
        int left=*max_element(nums.begin(),nums.end());
        int right=accumulate(nums.begin(),nums.end(),0);
        int ans=0;

        while(left<=right){
            int mid=left+(right-left)/2;
            if(isValid(nums,mid,days)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};