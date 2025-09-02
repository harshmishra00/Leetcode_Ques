class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        unordered_set<int> s;
        int a,b;
        vector<int> vec;
        int actual=0, expected=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                actual+=grid[i][j];

                if(s.find(grid[i][j])!= s.end()){
                    a=grid[i][j];
                    vec.push_back(a);
                }
                s.insert(grid[i][j]);
            }
            
        }
        expected=(n*n) * ((n*n+1))/2;
        b=expected+a-actual;
        vec.push_back(b);
        return vec;
    }
};