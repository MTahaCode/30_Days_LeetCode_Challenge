class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        set<vector<int>> unique_combinations;

        for (int i = 0; i < nums.size(); i++)
        {
            int lower_index = i + 1;
            int upper_index = nums.size() - 1;

            while (lower_index < upper_index)
            {
                int sum = nums[i] + nums[lower_index] + nums[upper_index];

                if (sum < 0)
                {
                    lower_index++;
                }
                else if (sum > 0)
                {
                    upper_index--;
                }
                else
                {
                    unique_combinations.insert({ nums[i], nums[lower_index], nums[upper_index] });
                    lower_index++;
                    upper_index--;
                }
            }
        }

        vector<vector<int>> Final(unique_combinations.begin(), unique_combinations.end());

        return Final;

    }
};