class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        vector<int> Final(nums.size(), 1);

        int product = 1;
        for (int i = 0; i < Final.size(); i++)
        {
            product = getLeftProduct(nums, i, product);

            Final[i] *= product;
        }

        product = 1;
        for (int i = Final.size() - 1; i >= 0; i--)
        {
            product = getRightProduct(nums, i, product);

            Final[i] *= product;
        }

        return Final;
    }
    
    int getLeftProduct(vector<int>& nums, int index, int prevProd)
    {
        if (index > 0 && index < nums.size())
        {
            return prevProd * nums[index - 1];
        }
        return prevProd;
    }

    int getRightProduct(vector<int>& nums, int index, int prevProd)
    {
        if (index >= 0 && index < nums.size() - 1)
        {
            return prevProd * nums[index + 1];
        }
        return prevProd;
    }
};