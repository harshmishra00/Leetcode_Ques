class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int totalOnes = 0;
        
        // Count total number of ones
        for (char c : s) {
            if (c == '1') totalOnes++;
        }
        
        int zeros = 0, ones = 0, maxScore = 0;
        
        // Traverse until n-1 (can't split after last character)
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == '0') zeros++;
            else ones++;
            
            int leftScore = zeros;
            int rightScore = totalOnes - ones;
            maxScore = max(maxScore, leftScore + rightScore);
        }
        
        return maxScore;
    }
};
