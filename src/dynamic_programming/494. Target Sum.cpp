/**
 * 这是个很有意思的问题
 * 方法一：首先我使用回溯法遍历所有解空间去寻找答案，这个办法很容易想到，
 * 实现起来也很简单，但是这种方法不够巧妙，时间复杂度是指数级别
 * 方法二：利用DP方式求解，但是需要发现其中的内在问题
 * 我们可以把这个问题变成，求nums数组的一个子集和为P，剩下的子集和取反设为N，
 * 所以现在的问题是我们需要找到满足 P + N = S 的子集数量。
 * 同时有 P - N = sum(nums的和)，所以有2*P = sum + S (这里有一点，如果sum + S为奇数时，肯定不存在解)
 * 于是问题又变成了我们需要找到nums数组中子集和为P = (sum + S)/2 的个数。
 * 状态：此时我们使用dp[k]表示子集和为k的数目, 0 <= k <= P
 * 方程：dp[k] = dp[k-num1] + dp[k-num2] + ... , num∈nums[] && num <= k
 * 初始化：dp[0] = 0
 * 什么时候更新：大致思路是，每次我们从nums[]中拿出一个值，
 * 然后看这个值和之前拿出来的值能够组成的和，然后更新dp[]。这里还要注意一点
 * 我们现在在求子集和，所以每个数字只能用一次，这样，如果我们拿到一个值num,
 * 然后按照k从小到大更新dp[k]，此时很有可能dp[k] += dp[k - num], 然而因为是从小到大更新
 * 所以很可能在更新dp[k-num] += dp[k-num - num]已经使用过一次num，这样会发生重复使用num的情况。
 * 为了避免这种情况，我们从后向前更新dp[k]，这也是DP问题中经常使用的方法
 * 此时 dp[k] = dp[k-num], dp[k-num]中的值都是之前的值组成的和，不会存在um复用的情况
 * 好啦，思路理顺了，剩下的就是代码实现啦。
 **/

class Solution {
public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
        helper(nums, S, 0);
        return count;
    }
    
    void helper(vector<int>& nums, int S, int pos){
        if(pos == nums.size()) {
            if(S ==0) count++;
            return;
        }
        helper(nums, S-nums[pos], pos+1);
        helper(nums, S+nums[pos], pos+1);
    }
};

class Solution {
public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum < S || sum + S & 1) return 0; //如果sum<S 或者sum+S为奇数的时候，直接返回0
        int P = (sum + S)/2;
        vector<int> dp(P+1, 0);
        dp[0] = 1;
        for(int n : nums){
            for(int i=P; i>=n; i--){
                dp[i] += dp[i-n];
            }
        }
        return dp[P];
    }
};