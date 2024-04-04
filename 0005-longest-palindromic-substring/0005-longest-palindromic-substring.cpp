class Solution {
public:
    string longestPalindrome(string s) {
        
        //adding hashes at each interval
        string hashedString;

        for (int i = 0; i < s.length(); ++i)
        {
            hashedString += "#";
            hashedString += s[i];
        }
        hashedString += "#";

        //manachers algorithm
        vector<int> palindromeSize(hashedString.length(), 0);

        int longest_palindrome_center = 0;
        int longest_palindrome_right_boundry = 0;

        string longest_palindrome = "";
        for (int i = 0; i < hashedString.length(); i++)
        {
            if (i < longest_palindrome_right_boundry) //withing boundry of longest
            {
                palindromeSize[i] = min(longest_palindrome_right_boundry - i, 
                    palindromeSize[2 * longest_palindrome_center - i]);
            }

            while (i - palindromeSize[i] - 1 >= 0
                && i + palindromeSize[i] + 1 < hashedString.length()
                && hashedString[i - palindromeSize[i] - 1] == hashedString[i + palindromeSize[i] + 1])
            {
                palindromeSize[i]++;
            }

            if (i + palindromeSize[i] > longest_palindrome_right_boundry)
            {
                longest_palindrome_center = i;
                longest_palindrome_right_boundry = i + palindromeSize[i];
            }

            if (palindromeSize[i] > longest_palindrome.length())
            {
                longest_palindrome = hashedString.substr(i - palindromeSize[i], 2 * palindromeSize[i] + 1);
                longest_palindrome.erase(std::remove(longest_palindrome.begin(), 
                                                     longest_palindrome.end(), '#'), 
                                                     longest_palindrome.end());
            }
        }
        return longest_palindrome;
    }
};