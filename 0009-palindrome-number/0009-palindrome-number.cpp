class Solution {
public:
    bool isPalindrome(int x) {
        string num = to_string(x);

        for (int i = 0; i < num.length() / 2; i++)
        {
            int fromEnd = num.length() - 1 - i;
            if (num[i] != num[fromEnd])
            {
                return false;
            }
        }
        return true;
    }
};