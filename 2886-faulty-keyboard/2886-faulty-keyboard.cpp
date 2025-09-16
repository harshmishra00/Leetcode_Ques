class Solution {
public:
    string finalString(string s) {
        int n=s.size();
        string str="";
        for(int i=0;i<n;i++){
            if(s[i]!='i'){
                str+=s[i];
            }
            else{
                reverse(str.begin(),str.end());
            }
        }
        return str;
    } 
};