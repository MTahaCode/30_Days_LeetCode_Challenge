class Solution {
public:
    bool isPerfectSquare(int num) {
        
        long int curr = 1;
        
        while (curr * curr <= num)
        {
            if ((long)(curr * curr) == (long)(num))
            {
                return true;
            }
            curr++;
        }
        return false;
    }
};