class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n  == 0)return 0;
        if(n == 1)return nums[0];
        if(n == 2)return max(nums[0],nums[1]);
        int A = nums[0];
        int B  = max(nums[0],nums[1]);
        int answer1 =  0;
        for(int i = 2;i<n-1;i++){
            answer1 = max(nums[i] + A,B);
            A = B;
            B = answer1;
        }
        answer1 = B;
        

        int C = nums[1];
        int D = max(nums[1],nums[2]);
        int answer2 = 0;
        for(int i = 3;i<n;i++){
            answer2 = max(nums[i] + C,D);
            C = D;
            D = answer2;
        }
        answer2 = D;

        int maxamount = max(answer1,answer2);
        return maxamount;
    
        
    }
};
