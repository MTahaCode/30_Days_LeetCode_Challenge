class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if (dividend == divisor) return 1;

        unsigned int divid = abs(dividend);
        unsigned int divis = abs(divisor);
        unsigned int Final = 0;

        while (divid >= divis) {
            uint32_t multiplier = 0;
            while (divid > divis << (multiplier + 1)) {
                multiplier++;
            }
            Final += 1 << multiplier;
            divid = divid -  (divis << multiplier);
        }
        if (Final == (1 << 31) && (dividend < 0 == divisor < 0)) {
            return INT_MAX;
        }
        return (dividend < 0 == divisor < 0) ? Final: -Final;
    }
};