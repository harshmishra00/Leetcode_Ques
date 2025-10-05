class Solution {
public:
    int m, n;
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int r, int c, vector<vector<int>>& h, vector<vector<bool>>& vis, int prev){
        if(r<0 || c<0 || r>=m || c>=n || vis[r][c] || h[r][c]<prev) return;
        vis[r][c]=true;
        for(auto &d: dirs)
            dfs(r+d[0], c+d[1], h, vis, h[r][c]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size(), n=heights[0].size();
        vector<vector<bool>> pac(m, vector<bool>(n,false)), atl(pac);
        
        for(int i=0;i<m;i++){
            dfs(i,0,heights,pac,heights[i][0]);       
            dfs(i,n-1,heights,atl,heights[i][n-1]);  
        }
        for(int j=0;j<n;j++){
            dfs(0,j,heights,pac,heights[0][j]);       
            dfs(m-1,j,heights,atl,heights[m-1][j]);  
        }
        
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(pac[i][j] && atl[i][j]) ans.push_back({i,j});
        return ans;
    }
};
