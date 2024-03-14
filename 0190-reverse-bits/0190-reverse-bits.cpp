class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t Final = 0xb1;

        for (int i = 0; i < 32; i++)
        {
            Final <<= 1;
            Final |= (n & 0b1);

            n >>= 1;
        }
        return Final;
    }
};