class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int, int> nums_map;

        for (int i = 0; i < nums.size(); i++)
        {
            nums_map[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int difference = target - nums[i];

            if (nums_map.find(difference) != nums_map.end() && nums_map[difference] != i)
            {
                return vector<int>{nums_map[difference], i};
            }
        }
        return vector<int>();
    }
};