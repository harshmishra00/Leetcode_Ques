class Solution {
public:

    bool isValid(vector<int>& nums,int mid,int m, int k){
        int n=nums.size();
        int count=0;
        int flower=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=mid){
                count++;
                if(count==k){
                    flower++;
                    count=0;
                }
            }else{
                count=0;
            }
        }
        return flower>=m;
    }
    int minDays(vector<int>& nums, int m, int k) {
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        int ans=-1;

        while(left<=right){
            int mid=left+(right-left)/2;

            if(isValid(nums,mid,m,k)){
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }return ans;
    }
};