class Solution {
public:
    string largestGoodInteger(string str) {
        int n=str.size();
        string maxNum="";
        for(int i=2;i<n;i++){
            if(str[i]==str[i-1] && str[i]==str[i-2]){
                string triple= string(3,str[i]);
                if(maxNum.empty() || triple>maxNum){
                    maxNum=triple;
                }
            }
        }
        return maxNum;
    }
};