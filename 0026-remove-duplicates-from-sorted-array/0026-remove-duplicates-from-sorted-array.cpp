class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        unordered_map<int, int> numsCount;

        for (int num : nums)
        {
            numsCount[num]++;
        }

        int index = 0;
        for (int i = nums[0]; i <= nums[nums.size() - 1]; i++)
        {
            if (numsCount[i] > 0)
            {
                nums[index] = i;
                index++;
            }
        }
        
        return index; 
    }
};