class Solution {
public:
    int climbStairs(int n) {
        
        int first = 0;
        int last = 1;

        for (int i = 0; i < n; i++)
        {
            int temp = first + last;
            first = last;
            last = temp;
        }

        return last;
        
    }
};