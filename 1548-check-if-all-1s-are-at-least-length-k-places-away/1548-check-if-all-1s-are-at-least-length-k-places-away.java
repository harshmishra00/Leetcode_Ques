class Solution {
    public boolean kLengthApart(int[] nums, int k) {
        int last = -100000; // store the index of previous 1
        
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == 1) {
                // if this is not the first 1, check distance
                if (i - last - 1 < k) return false;
                last = i;
            }
        }
        
        return true;
    }
}
