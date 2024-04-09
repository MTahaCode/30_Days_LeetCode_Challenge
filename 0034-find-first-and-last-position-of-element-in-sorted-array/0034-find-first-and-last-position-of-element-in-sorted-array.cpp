class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range(2, -1);
        
        int start = 0;
        int end = nums.size() - 1;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            
            if (target > nums[mid]) {
                start = mid + 1;
            }
            else if (target < nums[mid]) {
                end = mid - 1;
            }
            else {
                range[0] = mid;
                range[1] = mid;

                while (range[0] - 1 >= 0 && nums[range[0] - 1] == target) {
                    range[0]--;
                }
                
                while (range[1] + 1 < nums.size() && nums[range[1] + 1] == target) {
                    range[1]++;
                }
                break;
            }
        }
        return range;
    }
};