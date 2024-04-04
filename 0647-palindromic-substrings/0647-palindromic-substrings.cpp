class Solution {
public:
    int countSubstrings(string s) {
        //adding hashes at each interval
        string hashedString;

        for (int i = 0; i < s.length(); i++)
        {
            hashedString += "#";
            hashedString += s[i];
        }
        hashedString += "#";

        //counting
        int count = s.length();//initializing to all number of substrings

        for (int i = 0; i < hashedString.length(); i++)
        {
            int leftMost = i - 1;
            int rightMost = i + 1;

            while (leftMost >= 0 
                && rightMost < hashedString.length()
                && hashedString[leftMost] == hashedString[rightMost])
            {
                if (hashedString[leftMost] != '#')
                {
                    count++;
                }
                leftMost--;
                rightMost++;
            }
        }
        return count;
    }
};