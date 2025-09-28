class Solution {
public:
    int largestPerimeter(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=n-1;i>=2;i--){
            if(arr[i-2]+arr[i-1]>arr[i]){
                return arr[i-2]+arr[i-1]+arr[i];
            }
        }
        return 0;
        
    }
};