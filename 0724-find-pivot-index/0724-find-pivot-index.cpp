class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0,cs=0,rs;
        for(int val:nums){
            sum+=val;
        }
        for(int i=0;i<nums.size();i++){
            rs=sum-cs-nums[i];
            if(rs==cs){
                return i;
            }
            cs+=nums[i];
        }
        return -1;

    }
};