class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int hayStart = 0;
        int hayEnd = 0;
        
        int needleIndex = 0;
        
        for (hayEnd = 0; hayEnd < haystack.length(); hayEnd++)
        {
            if (needleIndex >= needle.length())
            {
                cout << "returned\n";
                return hayStart;
            }
            
            if (haystack[hayEnd] == needle[needleIndex])
            {
                if (needleIndex == 0)
                {
                    hayStart = hayEnd;
                }
                needleIndex++;
                cout << hayStart << endl;
            }
            else
            {
                needleIndex = 0;
                hayEnd = ++hayStart;
                hayEnd--;
            }
        }
        
        return (hayEnd - hayStart < needle.length()) ? -1 : hayStart;
    }
};