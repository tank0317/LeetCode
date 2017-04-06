/**
 * 这是一个非常有意思的题目
 * 方法一通过递归，遍历所有可能去解决问题
 * 方法二，为了避免递归中出现的重复操作，我们使用一个数组来存放中间量
 * 方法三，使用DP，避免使用暴力递归的方式
 * 方法四，在方法三的基础上，优化了间复杂度，
 **/

 //方法一
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1) >= 0;
    }
    
    int helper(vector<int>& nums, int s, int e){
        return s == e ? nums[s] : max(nums[s] - helper(nums, s+1, e), nums[e] - helper(nums, s, e-1));
    }
};

//方法二
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int>> mem(nums.size(), vector<int>(nums.size(), 999999999));
        return helper(nums, 0, nums.size()-1, mem) >= 0;
    }
    
    int helper(vector<int>& nums, int s, int e, vector<vector<int>>& mem){
        if(mem[s][e] == 999999999){
            mem[s][e] = s == e ? nums[s] : max(nums[s] - helper(nums, s+1, e, mem), nums[e] - helper(nums, s, e-1, mem));
        }
        return mem[s][e];
    }
};

//方法三
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++) dp[i][i] = nums[i];
        for(int len=1; len<n; len++){
            for(int s=0; s+len<n; s++){
                int e = s+len;
                dp[s][e] = max(nums[s] - dp[s+1][e], nums[e] - dp[s][e-1]);
            }
        }
        return dp[0][n-1]>=0;
    }
};

//方法四
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(nums);
        for(int len=1; len<n; len++){
            for(int e=n-1; e-len>=0; e--){
                int s = e-len;
                dp[e] = max(nums[s] - dp[e], nums[e] - dp[e-1]);
            }
        }
        return dp[n-1]>=0;
    }
};