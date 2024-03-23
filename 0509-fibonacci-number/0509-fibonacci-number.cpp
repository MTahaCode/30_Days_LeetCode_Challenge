class Solution {
public:
    int fib(int n) {
        
        int first = 1;
        int second = 1;

        if ( n <= 0)
        {
            return 0;
        }
        else if (n == 1)
        {
            return first;
        }

        for (int i = 3; i <= n; i++)
        {
            int temp = first + second;
            first = second;
            second = temp;
            cout << first << " " << second;
        }
        return second;
        
    }
};