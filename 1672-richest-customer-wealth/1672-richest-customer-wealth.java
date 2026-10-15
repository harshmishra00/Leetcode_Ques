class Solution {
    public int maximumWealth(int[][] acc) {
        int maxSum=Integer.MIN_VALUE;
        for(int i=0;i<acc.length;i++){
            int sum=0;
            for(int j=0;j<acc[0].length;j++){
                sum+=acc[i][j];
            }
            maxSum=Math.max(maxSum, sum);

        }
        return maxSum;
    }
}