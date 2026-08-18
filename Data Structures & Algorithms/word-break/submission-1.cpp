class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        int maxlen = 0;
        for(auto x : wordDict){
            maxlen = max(maxlen,(int)x.length());
        }
        vector<bool> dp(n + 1,false);
        dp[0] = true;
        unordered_set <string> wordset(wordDict.begin(),wordDict.end());
        for(int i = 1;i<=n;i++){
            for(int j  = i - 1;j >= max(0,i - maxlen);j--){
                if(dp[j] == true && wordset.count(s.substr(j,i-j)) == true){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
