class Solution {
public:
    int minimumRecolors(string s, int k) {
        int n=s.length();
        int currW=0;
        int left=0;

        for(int i=0;i<k;i++){
            if(s[i]=='W'){
                currW++;
            }
        }

        int minW=currW;

        for(int right=k;right<n;right++){
            if(s[left]=='W'){
                currW--;
            }
            if(s[right]=='W'){
                currW++;
            }
            left++;
            minW=min(currW,minW);
        }
        return minW;
    }
};