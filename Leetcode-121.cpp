class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxp=0;
        int bb=prices[0];
        for(int i=0;i<n;i++){
            if(prices[i]>bb){
                maxp=max(prices[i]-bb,maxp);
            }
            bb=min(prices[i],bb);

        }
        return maxp;
    }
};
