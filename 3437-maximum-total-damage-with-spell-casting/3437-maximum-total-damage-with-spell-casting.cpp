class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        unordered_map<int, long long> total;
        for (int p : power) total[p] += p;  

        vector<pair<int, long long>> spells(total.begin(), total.end());
        sort(spells.begin(), spells.end()); 

        int n = spells.size();
        vector<long long> dp(n);

        dp[0] = spells[0].second;

        for (int i = 1; i < n; i++) {
            long long take = spells[i].second;
            int j = i - 1;

            while (j >= 0 && spells[i].first - spells[j].first <= 2)
                j--;

            if (j >= 0) take += dp[j];

            dp[i] = max(dp[i - 1], take);
        }

        return dp[n - 1];
    }
};
