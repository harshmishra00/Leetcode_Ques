class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        
        int count=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' ||s[i]=='o' || s[i]=='u'){
                count++;
            }
        }
        int left=0;
        int right=k;
        int maxCount=count;

        while(right<n){
            if(s[right]=='a' || s[right]=='e' || s[right]=='i' ||s[right]=='o' || s[right]=='u'){
                count++;
            }

            if(s[left]=='a' || s[left]=='e' || s[left]=='i' ||s[left]=='o' || s[left]=='u'){
                count--;
            }

            if(maxCount<count){
                maxCount=count;
            }
            
            right++;
            left++;
        }
        return maxCount;
    }
};