class Solution {
public:
    int maxScore(string s) {
        int result=INT_MIN;
        int n=s.size();
        for(int i=0;i<n-1;i++){
            int zeroCount=0;
            for(int j=0;j<=i;j++){
                
                if(s[j]=='0'){
                    zeroCount++;
                }
            }
            int oneCount=0;
            for(int j=i+1;j<n;j++){
                
                if(s[j]=='1'){
                    oneCount++;
                }
            }

            result=max(result,zeroCount+oneCount);
        }
        return result;
    }
};