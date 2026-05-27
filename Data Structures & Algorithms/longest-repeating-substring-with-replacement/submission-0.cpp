class Solution {
   public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int n = s.size();
        int windowlength = 0;
        int maxwindow = 0;
        int maxfreq = 0;
        unordered_map<char,int> umap;
        for(int right = 0;right<n;right++){
            umap[s[right]]++;
            maxfreq = max(maxfreq,umap[s[right]]);
            windowlength = right - left + 1;
            if(windowlength - maxfreq > k){
                umap[s[left]]--;
                left++;
            }
            windowlength = right - left + 1;
            maxwindow = max(maxwindow,windowlength);
        }
        return maxwindow;
    }
};
