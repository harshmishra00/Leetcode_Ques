class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> power(n), diff(n + 1);
        long long l = 0, rmax = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            int left = max(0, i - r), right = min(n - 1, i + r);
            diff[left] += stations[i];
            if (right + 1 < n) diff[right + 1] -= stations[i];
        }
        power[0] = diff[0];
        for (int i = 1; i < n; i++) power[i] = power[i - 1] + diff[i];
        long long low = *min_element(power.begin(), power.end());
        long long high = accumulate(stations.begin(), stations.end(), 0LL) + k;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (can(power, n, r, k, mid)) {
                ans = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return ans;
    }

    bool can(vector<long long> power, int n, int r, long long k, long long target) {
        vector<long long> diff(n + 1);
        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += diff[i];
            power[i] += sum;
            if (power[i] < target) {
                long long need = target - power[i];
                if (need > k) return false;
                k -= need;
                sum += need;
                if (i + 2 * r + 1 < n) diff[i + 2 * r + 1] -= need;
            }
        }
        return true;
    }
};
