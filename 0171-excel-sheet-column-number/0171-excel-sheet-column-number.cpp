class Solution {
public:
    int titleToNumber(string str) {
        int n=str.size();
        int x=0;
        for(int i=0;i<n;i++){
            x=x*26+((int)str[i]-64);
        
        
        }
        return x;
    }
};