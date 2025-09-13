class Solution {
public:
    int maxFreqSum(string s) {
        int freq[26] = {0};
        for (char c : s) freq[c - 'a']++;

        bool vowel[26] = {false};
        vowel['a' - 'a'] = true;
        vowel['e' - 'a'] = true;
        vowel['i' - 'a'] = true;
        vowel['o' - 'a'] = true;
        vowel['u' - 'a'] = true;

        int maxVowel = 0, maxConsonant = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                if (vowel[i])
                    maxVowel = std::max(maxVowel, freq[i]);
                else
                    maxConsonant = std::max(maxConsonant, freq[i]);
            }
        }
        return maxVowel + maxConsonant;
    }
};
