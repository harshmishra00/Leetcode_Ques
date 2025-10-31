class Solution {
public:
    vector<int> getSneakyNumbers(const vector<int>& nums) {
        constexpr int kMax = 100;             // since n ≤ 100 according to constraints :contentReference[oaicite:1]{index=1}
        vector<int> ans;
        vector<int> count(kMax + 1, 0);

        for (int num : nums) {
            if (++count[num] == 2) {
                ans.push_back(num);
                if (ans.size() == 2)      // once we found both duplicates, we can stop (optional)
                    break;
            }
        }
        return ans;
    }
};
