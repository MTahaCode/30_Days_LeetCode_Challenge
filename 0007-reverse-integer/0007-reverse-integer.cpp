class Solution {
public:
    int reverse(int x) {
        
        int sign = 1;
        string word_x = to_string(x);
        //sign catered in
        if (word_x[0] == '+') {
            word_x.erase(word_x.begin());
        }
        else if (word_x[0] == '-') {
            word_x.erase(word_x.begin());
            sign = -1;
        }
        //string reversed
        std::reverse(word_x.begin(), word_x.end());
        //removing leading zeros
        while (word_x[0] == ' ') {
            word_x.erase(word_x.begin());
        }
        long int Final = stoul(word_x);

        if (Final > INT_MAX) {
            return 0;
        }
        else {
            return sign * Final;
        }
    }
};