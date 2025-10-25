class Solution {
public:
    int totalMoney(int n) {
        int weekStart = 1;
        int total = 0;

        for(int i = 1; i <= n; i++) {
            total += weekStart + (i - 1) % 7; 
            
            if(i % 7 == 0) {
                weekStart++;
            }
        }
        
        return total;
    }
};
