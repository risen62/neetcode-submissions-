class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        int answer = 0;
        
        // Try each house as the starting point
        for (int start = 0; start < n; start++) {
            vector<bool> robbed(n, false);
            vector<bool> blocked(n, false);
            
            // Start by robbing the 'start' house
            int sum = nums[start];
            robbed[start] = true;
            
            // Block adjacent houses
            if (start > 0) blocked[start - 1] = true;
            if (start < n - 1) blocked[start + 1] = true;
            
            // Keep picking the maximum available house
            while (true) {
                int bestIdx = -1;
                int bestVal = -1;
                
                // Find the best available house (not robbed and not blocked)
                for (int i = 0; i < n; i++) {
                    if (!robbed[i] && !blocked[i] && nums[i] > bestVal) {
                        bestVal = nums[i];
                        bestIdx = i;
                    }
                }
                
                // No more houses available
                if (bestIdx == -1) break;
                
                // Rob this house
                robbed[bestIdx] = true;
                sum += bestVal;
                
                // Block adjacent houses
                if (bestIdx > 0) blocked[bestIdx - 1] = true;
                if (bestIdx < n - 1) blocked[bestIdx + 1] = true;
            }
            
            answer = max(answer, sum);
        }
        
        return answer;
    }
};