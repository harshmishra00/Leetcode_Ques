class Solution {
public:
    int helper(string& s, int left, int right){
        int count=0;
        while(left>=0 && right<=s.length() && s[left]==s[right]){
            count++;
            left--;
            right++;

        }
        return count;
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.length();i++){
            count+=helper(s,i,i);
            count+=helper(s,i,i+1);

        }
        return count;
    }
};