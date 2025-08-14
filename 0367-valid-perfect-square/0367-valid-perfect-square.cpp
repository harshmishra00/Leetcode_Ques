class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int sq=ceil(sqrt(num));
        if(sq*sq==num){
            return true;
        }
        else{
            return false;
        }
    }
};