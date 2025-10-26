class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n=arr.size();
        set<int> s(arr.begin(),arr.end());
        int i=0;
        for(int x : s) {
            arr[i++] = x;
        }
        return s.size();
    }
};