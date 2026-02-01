class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;

        for(int i=0;i<right;i++){
            if(nums[i]%2==0){
                swap(nums[i],nums[left]);
                left++;
            }else{
                swap(nums[i],nums[right]);
                right--;
                i--;
            }
            
        }
        return nums;
    }
};