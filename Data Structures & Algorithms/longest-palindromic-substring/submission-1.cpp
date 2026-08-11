class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxlen = 1;
        for (int center = 0; center < s.size(); center++) {
            // Case 1: Odd length
            int left = center;
            int right = center;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                int currentlen = right - left + 1;
                if (currentlen > maxlen) {
                    maxlen = currentlen;
                    start = left;
                }
                left--;
                right++;
            }
            
            // Case 2: Even length
            left = center;
            right = center + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                int currentlen = right - left + 1;
                if (currentlen > maxlen) {
                    maxlen = currentlen;
                    start = left;
                }
                left--;
                right++;
            }
        }
        
        return s.substr(start, maxlen);
    }
};