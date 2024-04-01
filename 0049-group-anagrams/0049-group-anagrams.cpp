class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        //using hasmap of sorted string to index
        //run through vector and sort each string 
            // if that value doesnt exist in map set it to an index then
        //add this string in that index 
        
        vector<vector<string>> Final;
        unordered_map<string, int> stringMap;
        
        int index = 0;
        for (string& originalStr : strs)
        {
            string curr = originalStr;
            std::sort(curr.begin(), curr.end());
            
            if (stringMap.find(curr) == stringMap.end()) //not in map
            {
                stringMap[curr] = index;
                index++;
                //this will always be latest yet
                Final.push_back(vector<string>());
            }
            Final[stringMap[curr]].push_back(originalStr);
        }
        return Final;
    }
};