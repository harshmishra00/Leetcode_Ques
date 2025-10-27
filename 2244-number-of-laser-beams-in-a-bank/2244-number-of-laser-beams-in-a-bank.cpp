class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0; 
        int beams = 0;

        for(string &row : bank) {
            int count = 0;
            for(char c : row) {
                if(c == '1') count++;
            }

            if(count > 0) {
                beams += prev * count;
                prev = count;
            }
        }
        return beams;
    }
};
