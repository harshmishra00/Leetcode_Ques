class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        vector<int> ans(arr.size());
        int pos=0;
        int neg=1;
        for(int val:arr){
            if(val>0){
                ans[pos]=val;
                pos+=2;
            }else{
                ans[neg]=val;
                neg+=2;
            }
        }
        return ans;
    }
};