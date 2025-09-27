// C++ (LeetCode)
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    long long x1 = points[j][0]-points[i][0];
                    long long y1 = points[j][1]-points[i][1];
                    long long x2 = points[k][0]-points[i][0];
                    long long y2 = points[k][1]-points[i][1];
                    double area = abs(x1*y2 - y1*x2) / 2.0;
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};
