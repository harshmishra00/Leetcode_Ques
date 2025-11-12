class Solution {
    public int minOperations(int[] nums) {
        int ones = 0;
        for (int x : nums) if (x == 1) ones++;
        if (ones > 0) return nums.length - ones;
        int n = nums.length, ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    ans = Math.min(ans, j - i + n - 1);
                    break;
                }
            }
        }
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    private int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
}
