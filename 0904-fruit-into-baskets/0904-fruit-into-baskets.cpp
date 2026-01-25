class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        int maxLen=0;
        unordered_map<int,int>m;
        int left=0;
        for(int right=0;right<n;right++){
            m[fruits[right]]++;

            while(m.size()>2){
                m[fruits[left]]--;
                if(m[fruits[left]]==0){
                    m.erase(fruits[left]);
                }
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};