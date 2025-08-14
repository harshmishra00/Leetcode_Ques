class Solution {
public:
    int search(vector<int>& arr, int tar) {
        int st=0, end=arr.size()-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(arr[mid]==tar){
                return mid;
            }

            if(arr[st]<=arr[mid]){
                if(arr[st]<=tar && arr[mid]>=tar){
                    end=mid-1;
                }else{
                    st=mid+1;
                }
            }
            else{
                if(arr[mid]<=tar&& arr[end]>=tar){
                    st=mid+1;
                }else{
                    end=mid-1;
                }
            }

        }
        return -1;
    }
    

};