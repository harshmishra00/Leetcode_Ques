class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int st=0, end=arr.size()-1;
        int n=arr.size();
        if(n==1){
            return arr[0];
        }
        while(st<=end){
            int mid=st+(end-st)/2;
            
            if(mid==0 && arr[0]!=arr[1]){
                return arr[mid];
            }
            if(mid==n-1 && arr[n-1]!=arr[n-2]){
                return arr[mid];
            }

            if(arr[mid]!=arr[mid-1]&&arr[mid]!=arr[mid+1]){
                return arr[mid];
            }

            if(mid%2==0){//even
                if(arr[mid]==arr[mid-1]){
                    end=mid-1;
                }else{
                    st=mid+1;
                }

            }else{//odd
                if(arr[mid]==arr[mid-1]){
                    st=mid+1;
                }else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};