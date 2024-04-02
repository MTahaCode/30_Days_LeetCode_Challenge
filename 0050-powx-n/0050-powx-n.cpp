class Solution {
public:
    double myPow(double x, int n) {
        
        int n_changing = abs(n);
        
        double Final = 1;
        
        while (n_changing > 0)
        {
            if (n_changing % 2 == 0)
            {
                x *=x;
                n_changing = n_changing / 2;
            }
            else
            {
                Final *= x;
                n_changing--;
            }
        }
        
        return (n > 0) ? Final : 1.0/Final;
    }
};