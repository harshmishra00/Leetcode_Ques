class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        priority_queue<array<int,3>, vector<array<int,3>>, greater<>> pq;
        pq.push({grid[0][0], 0, 0});
        vis[0][0] = 1;
        
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        int ans = 0;
        
        while(!pq.empty()){
            auto [h, x, y] = pq.top();
            pq.pop();
            ans = max(ans, h);
            if(x == n-1 && y == n-1) return ans;
            
            for(auto &d: dirs){
                int nx = x + d[0], ny = y + d[1];
                if(nx>=0 && ny>=0 && nx<n && ny<n && !vis[nx][ny]){
                    vis[nx][ny] = 1;
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }
        return ans;
    }
};
