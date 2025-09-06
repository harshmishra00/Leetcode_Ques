class Solution {
public:
    char findTheDifference(string s, string t) {
        int Xor=0;
        for(char ch : s){
            Xor^=ch;
        }
        for(char ch : t){
            Xor^=ch;
        }
        return (char)Xor;
    }
};