class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1_index = m;

        for (int curr : nums2)
        {
            nums1[nums1_index] = curr;

            for (int i = nums1_index; i >= 1; i--)
            {
                if (nums1[i] < nums1[i - 1])
                {
                    swap(nums1[i], nums1[i - 1]);
                }
                else
                {
                    break;
                }
            }

            nums1_index++;
        }
    }
};