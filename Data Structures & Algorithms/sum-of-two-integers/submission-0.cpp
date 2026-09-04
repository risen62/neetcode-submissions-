class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            // Calculate carry (only where both bits are 1)
            int carry = (a & b) << 1;
            
            // Calculate sum without carry using XOR
            a = a ^ b;
            
            // Set b to carry for next iteration
            b = carry;
        }
        return a;
    }
};