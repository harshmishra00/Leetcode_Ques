class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> nums(s.length(),0);

        for(int i=0;i<s.length();i++){
            nums[i]=abs(s[i]-t[i]);
        }
        int left=0;
        int right=0;
        int sum=0;
        int maxLen=0;
        while(right<nums.size()){
            sum+=nums[right];
            while(sum>maxCost){
                sum-=nums[left];
                left++;
            }
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};