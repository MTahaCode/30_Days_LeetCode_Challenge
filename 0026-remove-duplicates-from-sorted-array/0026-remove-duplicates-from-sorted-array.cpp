class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int k = 0;

        for (int num : nums)
        {
            if (num != nums[k])
            {
                k++;
                nums[k] = num;
            }
        }
        return k+1;
    }
};