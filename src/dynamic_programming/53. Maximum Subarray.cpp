/**
 * 动态规划题目
 * 使用固定套路解答
 **/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> dp(nums.size(), INFINITY);
        dp[0] = nums[0];
        int maxSum = dp[0];
        for(int i=1; i<nums.size(); i++){
            dp[i] = nums[i] + (dp[i-1] > 0 ? dp[i-1] : 0);
            maxSum = max(dp[i], maxSum);
        }
        return maxSum;
    }
};