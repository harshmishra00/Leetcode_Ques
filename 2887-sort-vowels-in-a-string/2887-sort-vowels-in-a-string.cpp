class Solution {
public:
    string sortVowels(string s) {
        int n = s.size();
        vector<char> vowels;
        vector<int> pos;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
                s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
                vowels.push_back(s[i]);
                pos.push_back(i);
            }
        }

        sort(vowels.begin(), vowels.end());
        string answer = s;

        for (int i = 0; i < pos.size(); i++) {
            answer[pos[i]] = vowels[i];
        }

        return answer;
    }
};
