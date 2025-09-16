class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.size();
        vector<char> vec;
        vector<int> pos;
        vector<char>str;
        for(int i=0;i<n;i++){
            if(isalpha(s[i])){
                vec.push_back(s[i]);
                pos.push_back(i);
            }
            
            
        }
        reverse(vec.begin(),vec.end());
        for(int i=0;i<pos.size();i++){
            s[pos[i]]=vec[i];
        }
        return s;
    }
};