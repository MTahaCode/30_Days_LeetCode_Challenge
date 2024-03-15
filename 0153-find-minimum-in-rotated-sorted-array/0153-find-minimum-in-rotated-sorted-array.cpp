class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int min = nums[nums.size() - 1];
        for (int i = nums.size() - 2; i>=0; i--)
        {
            if (nums[i] < min)
            {
                min = nums[i];
            }
            else
            {
                break;
            }
        }
        return min;
    }
};