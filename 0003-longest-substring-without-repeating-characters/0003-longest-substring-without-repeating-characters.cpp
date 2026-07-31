class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int left=0;
        int right=0;
        int maxLen=0;
        unordered_map<int,int>mp;

        while(right<=n-1){
            if(mp.find(s[right])!=mp.end() && mp[s[right]] >= left){
                left=mp[s[right]]+1;
            }
            mp[s[right]]=right;
            maxLen=max(maxLen,right-left+1);
            right++;
        }
        return maxLen;
    }
};