class Solution {
public:
    int addDigits(int num) {
        int sum=0;
        if(num<=9){
            return num;
        }
        else{
            while(num>9){
                int rem=num%10;
                int q=num/10;
                sum=rem+q;
                num=sum;
            }
            return sum;
        }
    }
};
