/**
 * 一维动态规划题目
 * 方法一使用典型动态规划的思路实现
 * 方法二思路是一样的，但是不申请数组保存每一个状态的值
 **/

 //方法一
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

//方法二
class Solution {
public:
    int climbStairs(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        int a = 1;
        int b = 2;
        int c = 0;
        for(int i=3; i<=n; i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};