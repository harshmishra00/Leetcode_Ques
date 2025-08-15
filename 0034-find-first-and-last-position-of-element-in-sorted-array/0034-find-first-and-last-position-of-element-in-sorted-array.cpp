class Solution {
public:

    int first(vector<int> arr, int tar){
        int st=0, end=arr.size()-1, ans=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(arr[mid]>=tar){
                end=mid-1;
            }else{
                st=mid+1;
            }
            if(arr[mid]==tar){
                ans=mid;
            }

        }
        return ans;
    }

    int second(vector<int> arr, int tar){
        int st=0, end=arr.size()-1, ans=-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(arr[mid]<=tar){
                st=mid+1;
            }else{
                end=mid-1;
            }
            if(arr[mid]==tar){
                ans=mid;
            }

        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {first(nums,target), second(nums,target)};
    }
};