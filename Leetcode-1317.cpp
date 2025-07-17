bool isNoZero(int n){
    while (n > 0) {
        if (n % 10 == 0) return false;
        n/= 10;
    }
    return true;
}
class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        vector<int> vec;
        bool f=false;
        for(int i=1;i<n && !f;i++){
            for(int j=1;j<n;j++){
                if(i+j==n){
                    if(isNoZero(i) && isNoZero(j)){
                        vec.push_back(i);
                        vec.push_back(j);
                        f=true;
                        break;
                    }
                }
            }
        }
        return vec;
    }
};
