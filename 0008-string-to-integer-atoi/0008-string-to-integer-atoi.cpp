class Solution {
public:
    int myAtoi(string s) {
        int index = 0;
        int isPositive = 1;
        long int Final = 0;

        //all white spaces skipped
        while (s[index] == ' ') index++;
        //sign catered in
        if (s[index] == '+') {
            index++;
        }
        else if (s[index] == '-') {
            isPositive = -1;
            index++;
        }
        //taking in all the values and building the number
        while (s[index] >= '0' && s[index] <= '9') {
            Final *= 10;
            Final += (s[index] - '0');
            if (Final > INT_MAX) {
                return (isPositive == 1) ?  INT_MAX: INT_MIN;
            }
            index++;
        }
        if (Final > INT_MAX) {
            return (isPositive == 1) ?  INT_MAX: INT_MIN;
        }
        else {
            return Final * isPositive;
        }
    }
};