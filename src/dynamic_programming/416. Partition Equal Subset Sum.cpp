/**
 * 状态：使用dp[k]表示是否有子集和为k, 值只有0和1，表示有和没有 , 0 <= k <= P
 * 方程：dp[k] = dp[k-num1] || dp[k-num2] || ... , num∈nums[] && num <= k
 * 初始化：dp[0] = 0
 * 什么时候更新：大致思路是，每次我们从nums[]中拿出一个值，
 * 然后看这个值和之前拿出来的值能够组成的和，然后更新dp[]。这里还要注意一点
 * 我们现在在求子集和，所以每个数字只能用一次，这样，如果我们拿到一个值num,
 * 然后按照k从小到大更新dp[k]，此时很有可能dp[k] = dp[k] || dp[k - num], 然而因为是从小到大更新
 * 所以很可能在更新dp[k-num] = dp[k-num] || dp[k-num - num]已经使用过一次num，这样会发生重复使用num的情况。
 * 为了避免这种情况，我们从后向前更新dp[k]，这也是DP问题中经常使用的方法
 * 此时 dp[k] = dp[k] || dp[k-num], dp[k-num]中的值都是之前的值组成的和，不会存在um复用的情况
 * 好啦，思路理顺了，剩下的就是代码实现啦。
 **/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum & 1) return false;
        vector<int> dp(sum/2 + 1, 0);
        dp[0] = 1;
        for(int num : nums){
            for(int i=sum/2; i>=num; i--){
                dp[i] = dp[i] || dp[i-num];
                if(i==sum/2 && dp[i]) return true;
            }
        }
        return false;
    }
};