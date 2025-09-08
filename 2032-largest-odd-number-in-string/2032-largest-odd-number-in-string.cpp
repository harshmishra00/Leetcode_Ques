class Solution {
public:
    string largestOddNumber(string str) {
        int n=str.size();
        for(int i=n-1;i>=0;i--){
            if((str[i]-'0')%2!=0){
                return str.substr(0,i+1);
            }
        }
        return "";
    }   
};