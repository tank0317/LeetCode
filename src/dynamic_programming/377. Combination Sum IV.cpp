/**
 * 状态：dp[i]，0 <= i <= target; 代表target为i时的序列数量。
 * 状态方程： dp[target] = sum(dp[target - nums[i]]), where 0<=i<nums.size(), nums[i]<=target;
 * 初始化：dp[0] = 1;
 **/
 
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        for(int i=1; i<=target; i++){
            for(int j=0; j<nums.size(); j++){
                if(nums[j] <= i){
                    dp[i] += dp[i-nums[j]];
                }
            }
        }
        return dp[target];
    }
};