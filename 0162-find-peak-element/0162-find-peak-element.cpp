class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 0;
        if(nums[0]>nums[1]) return 0;
        if(nums[n-1]>nums[n-2]) return n-1;
        int prev=0;
        int curr=1;
        int next=2;
        while(next<n){
            if(nums[curr]>nums[prev] && nums[curr]>nums[next]){
                return curr;
            }
            next++;
            curr++;
            prev++;
        }
        return -1;
    }
};