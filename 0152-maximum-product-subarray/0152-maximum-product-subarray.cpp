class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        
        int total = 1;
        int max_val = nums[0];
        for (int curr : nums)
        {
            total *= curr;
            
            max_val = max(total, max_val);
            
            if (total == 0)
            {
                total = 1;
            }
        }
        
        total = 1;
        for (int curr = nums.size() - 1; curr >= 0; curr--)
        {
            total *= nums[curr];
            
            max_val = max(total, max_val);
            
            if (total == 0)
            {
                total = 1;
            }
        }
        return max_val;
    }
};