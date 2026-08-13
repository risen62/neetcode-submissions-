class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int>dp(n + 1);
        for(int i =  n - 1;i>=0;i--){
            dp[n] = 1;
            if(s[i] != '0'){
                dp[i] = dp[i] + dp[i + 1];
            }
            if(i + 1 < n){
                int first_digit = s[i] - '0';
                int second_digit = s[i+1] - '0';

                int twodigits = first_digit  * 10 + second_digit;
                if(twodigits >= 10 && twodigits <= 26){
                    dp[i] = dp[i] + dp[i + 2];
                }
            }

        }
        return dp[0];
    }
};
