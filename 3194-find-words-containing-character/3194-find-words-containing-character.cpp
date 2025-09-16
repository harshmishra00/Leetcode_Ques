class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n=words.size();
        vector<int> vec;
        for(int i=0;i<n;i++){
            if(words[i].find(x)!=string::npos){
                vec.push_back(i);
            }
        }
        return vec;
    }
};