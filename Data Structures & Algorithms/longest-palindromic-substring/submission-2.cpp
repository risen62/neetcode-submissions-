class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxlength = 1;
        for(int center = 0;center<s.size();center++){   //odd length
            int left  = center;
            int right = center;
            while(left >= 0 && right < s.size() && s[left] == s[right]){
                int currentlength = right - left  + 1;
                if(currentlength > maxlength){
                    maxlength = currentlength;
                    start = left;
                }
                left--;
                right++;
            }

            left = center;
            right  = center + 1;
            while(left >= 0 && right <= s.size() && s[left] == s[right]){
                int currentlength = right - left  + 1;
                if(currentlength > maxlength){
                    maxlength = currentlength;
                    start = left;
                }
                left--;
                right++;
            }
        }
        return s.substr(start,maxlength);
    }
};