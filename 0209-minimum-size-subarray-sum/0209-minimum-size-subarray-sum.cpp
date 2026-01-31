class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int left=0;
        int sum=0;
        int n=arr.size();
        int minLen=INT_MAX;

        for(int i=0;i<n;i++){
            sum+=arr[i];

            while(sum>=target){
                sum-=arr[left];
                minLen=min(minLen,i-left+1);
                left++;
            }
        }
        return minLen==INT_MAX ? 0:  minLen;
    }
};