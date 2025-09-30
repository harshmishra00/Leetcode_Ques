class Solution {
public:
    int triangularSum(vector<int>& nums) {
        vector<int> arr = nums;
        int n = arr.size();
        
        for (int size = n; size > 1; size--) {
            for (int i = 0; i < size - 1; i++) {
                arr[i] = (arr[i] + arr[i + 1]) % 10;
            }
        }
        return arr[0];
    }
};
