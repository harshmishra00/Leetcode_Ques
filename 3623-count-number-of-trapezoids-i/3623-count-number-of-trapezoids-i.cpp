class Solution {
public:

    long long nc2(long long n)
    {
        if(n < 2) return 0;
        else return n * (n - 1) / 2;
    }

    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, int> m;
        const int mod = 1e9 + 7;

        // Count number of points at each height
        for (auto P : points) {
            m[P[1]]++;
        }

        // Collect counts into a vector
        vector<long long> levelPoints;
        for (auto P : m)
            levelPoints.push_back(P.second);

        // Compute number of point-pairs at each height
        vector<long long> levelPairs;
        for (long long p : levelPoints)
            levelPairs.push_back(nc2(p));

        // Sum of all pairs
        long long sum = accumulate(levelPairs.begin(), levelPairs.end(), 0LL);

        long long ans = 0;

        // Compute pairwise products
        for (int i = 0; i < levelPairs.size(); i++) {
            sum -= levelPairs[i];
            ans += levelPairs[i] * sum;
            ans %= mod;
        }

        return ans % mod;
    }
};