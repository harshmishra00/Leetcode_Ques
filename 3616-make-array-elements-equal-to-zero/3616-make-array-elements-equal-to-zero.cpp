#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        for(int x : nums) totalSum += x;

        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int validCount = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] != 0) continue; 

            long long leftSum = (i > 0 ? prefix[i - 1] : 0);
            long long rightSum = totalSum - leftSum;

            long long diff = abs(leftSum - rightSum);

            if(diff == 0) validCount += 2;       
            else if(diff == 1) validCount += 1;   
            
        }

        return validCount;
    }
};
