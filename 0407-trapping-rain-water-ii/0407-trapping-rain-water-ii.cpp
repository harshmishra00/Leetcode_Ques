
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;
        

        using Cell = pair<int, pair<int,int>>;  
        priority_queue<Cell, vector<Cell>, greater<Cell>> pq;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        

        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = true;
            visited[i][n-1] = true;
        }
        
        for (int j = 1; j < n-1; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m-1][j], {m-1, j}});
            visited[0][j] = true;
            visited[m-1][j] = true;
        }
        
        int waterTrapped = 0;
        vector<int> dirs = {1, 0, -1, 0, 1};  
        
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();
            int height = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dirs[k];
                int ny = y + dirs[k+1];
                
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;

                    waterTrapped += max(0, height - heightMap[nx][ny]);

                    pq.push({max(heightMap[nx][ny], height), {nx, ny}});
                }
            }
        }
        
        return waterTrapped;
    }
};
