class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int start = 0;
        int end = 0;
        int size = 0;
        int maxFrequency = 0;
        map<char, int> alphabets;
        
        while (end < s.length())
        {
            alphabets[s[end]]++;
                      
            maxFrequency = max(maxFrequency, alphabets[s[end]]);
                      
            if (end - start + 1 - maxFrequency > k)
            {
                alphabets[s[start]]--;
                start++;
            }
            else
            {
                size = max(size, end - start + 1);
            }
            end++;
        }
        return size;
    }
};