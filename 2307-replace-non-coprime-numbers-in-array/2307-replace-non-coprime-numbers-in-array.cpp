class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int x : nums) {
            st.push_back(x);
            while (st.size() > 1) {
                int a = st[st.size()-2], b = st.back();
                int g = gcd(a,b);
                if (g == 1) break;
                st.pop_back(); st.pop_back();
                st.push_back(lcm(a,b));
            }
        }
        return st;
    }
};