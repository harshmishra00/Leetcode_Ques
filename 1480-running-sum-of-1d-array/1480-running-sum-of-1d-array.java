class Solution {
    public int[] runningSum(int[] nums) {
        int n=nums.length;
        int[] vec=new int[n];
        vec[0]=nums[0];
        for(int i=1;i<n;i++){
            vec[i]=vec[i-1]+nums[i];
        }
        return vec;
    }
}