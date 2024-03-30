class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        string Final = "";

        for (int i = 0; i < s.length(); i++)
        {
            string temp = "";
            for (int index = i; index < s.length(); index++)
            {
                if (temp.find(s[index]) != string::npos)
                {
                    break;
                }
                temp += s[index];
            }
            if (Final.length() < temp.length())
            {
                Final = temp;
            }
        }
        return Final.length();
    }
};