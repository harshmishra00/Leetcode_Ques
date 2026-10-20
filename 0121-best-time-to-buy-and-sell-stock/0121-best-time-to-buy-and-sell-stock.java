class Solution {
    public int maxProfit(int[] prices) {
        int min=prices[0];
        int maxPro=0;

        for(int i=0;i<prices.length;i++){
            if(min>prices[i]) min=prices[i];

            if(prices[i]-min>maxPro) maxPro=prices[i]-min;
        }

        return maxPro;
    }
}