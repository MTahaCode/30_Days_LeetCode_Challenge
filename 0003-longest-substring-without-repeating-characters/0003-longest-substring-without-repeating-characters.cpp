class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int MaxSize = 0;

        int i = 0;
        int j = 0;

        unordered_map<char, int> charMap;

        while (j < s.length())
        {
            //add to char map
            charMap[s[j]]++;

            if (charMap.size() == j - i + 1)
            {
                MaxSize = max(MaxSize, j - i + 1);
            }

            while (charMap.size() < j - i + 1)
            {
                charMap[s[i]]--;
                if (charMap[s[i]] == 0)
                {
                    charMap.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        return MaxSize;
    }
};