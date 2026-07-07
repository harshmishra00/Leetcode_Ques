class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x=n;
        long long sum=0;
        while(x>0){
            sum+=(x%10);
            x=x/10;
        }

        long long m=n;
        long long temp=0;
        while(m>0){
            if(m%10!=0){
                temp=temp*10+(m%10);
            }
            m/=10;
        }
        long long ans=0;
        while(temp>0){
            ans=ans*10 + temp%10;
            temp/=10;
        }

        return ans*sum;
    }
};