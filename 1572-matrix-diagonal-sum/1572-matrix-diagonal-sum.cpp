class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int ld=0;
        int rd=0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(i==j){
                    ld+=mat[i][j];
                }else if(j==n-1-i){
                    rd+=mat[i][j];
                }
            }
        }
        return ld+rd;
    }
};