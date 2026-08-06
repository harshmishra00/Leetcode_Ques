class Solution {
public:
    bool isValid(vector<int>&nums,int mid,int t){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(nums[i]/mid);
            if(nums[i]%mid!=0){
                sum+=1;
            }
        }
        return sum<=t;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        int ans=0;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(isValid(nums,mid,threshold)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        return ans;
    }
};