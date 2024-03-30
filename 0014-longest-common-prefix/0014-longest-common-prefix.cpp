class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string prefix = strs[0];
        
        int index = prefix.length();
        
        for (int i = 1; i < strs.size(); i++)
        {
            string& curr = strs[i];

            int temp = 0;
            while(temp < curr.length() && temp < prefix.length() && curr[temp] == prefix[temp])
            {
                temp++;
            }
            index = min(index, temp);
        }
        return prefix.substr(0, index);
    }
};