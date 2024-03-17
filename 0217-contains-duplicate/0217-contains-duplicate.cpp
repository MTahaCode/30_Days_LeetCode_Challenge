class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        map<int, int> nums_map;
        
        for (int curr : nums)
        {
            if (nums_map.find(curr) == nums_map.end())
            {
                nums_map[curr] = 1;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};