class Solution {
public:
    int reverse(int x) {
        long long num=0;
        while(x!=0){
            int rem=x%10;
            num=num*10+rem;
            if(num > INT_MAX || num < INT_MIN) { 
                return 0; 
            }
            x/=10;
        }
        return num;
    }
};