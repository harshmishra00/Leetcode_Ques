class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n=arr.size();
        int left=0;
        int right=n-1;
        int maxArea=0;
        while(left<right){
            int height=min(arr[left],arr[right]);
            int width=right-left;
            long long area=(long long)height*width;
            maxArea=max((int)area,maxArea);
            if(arr[left]<arr[right]){
                left++;
            }else{
                right--;
            }
        }
        return maxArea;
    }
};