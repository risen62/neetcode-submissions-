class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        
        // Process all 32 bits
        for (int i = 0; i < 32; i++) {
            // Shift result left to make room for next bit
            result <<= 1;
            
            // Extract the last bit of n and add it to result
            result |= (n & 1);
            
            // Shift n right to process next bit
            n >>= 1;
        }
        
        return result;
    }
};