class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int index = 0;

        string prefix = "";

        while (true)
        {
            char currChar = strs[0][index];
            for (string curr : strs)
            {
                if (index >= curr.length() || curr[index] != currChar)
                {
                    return prefix;
                }
            }
            prefix += currChar;
            index++;
        }
    }
};