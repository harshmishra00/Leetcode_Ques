class Solution {
public:
    string mergeAlternately(string word1, string word2) {
       int p1=0;
       int p2=0;
       int i=1;

       string s="";
       while(p1<word1.length() && p2<word2.length()){
        if(i%2!=0){
            s.push_back(word1[p1]);
            p1++;
        }else{
            s.push_back(word2[p2]);
                p2++;
        }
        i++;
       }
       while(p1<word1.length()){
        s.push_back(word1[p1]);
        p1++;
       }

       while(p2<word2.length()){
        s.push_back(word2[p2]);
        p2++;
       }

       return s;
    }
};