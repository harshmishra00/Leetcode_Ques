class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long int m=n;
        if (m<0){
            m=-m;
            x=1.0/x;
        }
        while(m>0){
            if(m%2==1){
                m=m-1;
                ans*=x;
            }
            m=m/2;
            x*=x;
        }
        return ans;

    }
};