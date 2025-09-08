class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& arr) {
        
        int m=arr.size();
        int n=arr[0].size();
        vector<vector<int>>result(n, vector<int>(m));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                swap(result[j][i],arr[i][j]);
            }
        }
        return result;
    }
};