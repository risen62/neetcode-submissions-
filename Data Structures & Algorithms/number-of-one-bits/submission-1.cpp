class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        int a = 1;
        while(n != 0 ){
            if((n & a) != 0 ){
                count++;
            }
             n = n >> 1;
        }
        return count;
    }
};
