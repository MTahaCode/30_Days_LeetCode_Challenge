class Solution {
public:
    int fib(int n) {
        
        map<int, int> fibNumbers;

        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || i == 2)
            {
                fibNumbers[i] = 1;
            }
            else
            {
                fibNumbers[i] = fibNumbers[i - 1] + fibNumbers[i - 2];
            }
        }   
        return fibNumbers[n];
        
    }
};