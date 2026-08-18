class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1,false);
        unordered_set<string> wordSet(wordDict.begin(),wordDict.end());
        int maxlen = 0;
        for(auto x : wordDict){
            maxlen = max(maxlen,(int)x.size());
        }
        dp[0]  = true;
        for(int i = 1;i<=n;i++){
            for(int j = i - 1;j>=max(0,i - maxlen);j--){
                if(dp[j] == true && wordSet.count(s.substr(j,i-j))){
                    dp[i] = true;
                    break;
                }

            }
        }
        return dp[n];
    }
};
