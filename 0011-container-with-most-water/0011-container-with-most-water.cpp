class Solution {
public:
    int maxArea(vector<int>& arr) {
        int n=arr.size();
        int left=0;
        int right=n-1;
        int maxArea=INT_MIN;
        while(left<right){
            int width =right-left;
            int height=min(arr[right],arr[left]);
            int area=width*height;
            maxArea=max(maxArea,area);
            if(arr[left]<arr[right]){
                left++;
            }else{
                right--;
            }
            
        }
        return maxArea;
    }
};