class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)return 1;
        if(n == 2)return 2;
        int previous_number1 = 1;
        int previous_number2 = 2;
        int answer;
        for(int i = 3;i<n + 1;i++){
            answer = previous_number1 + previous_number2;
            previous_number1 = previous_number2;
            previous_number2 = answer;
        }
        return answer;
    }
};
