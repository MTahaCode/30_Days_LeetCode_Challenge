class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int length = nums.size();

        int sum_of_all_digits = (length * (length + 1)) / 2;

        //sum of digits in the array
        int sum_of_array = 0;
        for (int curr : nums)
        {
            sum_of_array += curr;
        }

        return sum_of_all_digits - sum_of_array;
    }
};