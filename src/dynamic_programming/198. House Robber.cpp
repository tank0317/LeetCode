/**
 * 动态规划题目
 * 方法一使用动态规划的思路来解题
 * 方法二没有使用固定套路
 **/
 
 //方法一
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return nums[0] > nums[1] ? nums[0] : nums[1];
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = nums[0] > nums[1] ? nums[0] : nums[1];
        int maxVal = dp[1];
        for(int i=2; i<nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            maxVal = max(maxVal, dp[i]);
        }
        return maxVal;
    }
};

//方法二
class Solution {
public:
    int rob(vector<int>& nums) {
        int pre = 0;
        int cur = 0;
        for(int i=0; i<nums.size(); i++){
            int tmp = max(pre+nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};

