class Solution {
public:
    int search(vector<int>& arr, int target) {
        int n=arr.size();
        int st=0, end=n-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(target==arr[mid]){
                return mid;
            }
            if(target<arr[mid]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return -1;
    }
};