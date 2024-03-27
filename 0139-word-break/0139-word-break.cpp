class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        unordered_set<string> set_of_words = {wordDict.begin(), wordDict.end()};

        vector<bool> wordExistsTill(s.length() + 1, false);

        //here the index is starting from 1 not 0, 0 represents empty string
        wordExistsTill[0] = true;


        for (int i = 1; i <= s.length(); i++)
        {
            for (int j = i - 1; j >= 0; j--)
            {
                if (wordExistsTill[j] && set_of_words.count(s.substr(j, i - j)))
                {
                    wordExistsTill[i] = true;
                }
            }
        }

        return wordExistsTill[s.length()];
    }
};