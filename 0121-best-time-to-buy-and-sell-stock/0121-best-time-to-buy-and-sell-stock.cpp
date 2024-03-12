class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int min_day = INT_MAX;

        for (int curr : prices)
        {
            min_day = min(min_day, curr);

            if (curr - min_day > profit)
            {
                profit = curr - min_day;
            }
        }

        return profit;
    }
};