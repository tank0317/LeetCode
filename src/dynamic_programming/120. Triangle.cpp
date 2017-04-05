/**
 * DP经典题目
 * 状态：dp[i][j] 表示到位置(i, j)的最小路径
 * 状态方程：dp[i][j] = triangle[i][j] + min(dp[i][j-1], dp[i-1][j-1]), 0<i<m(行数) && 0<j<i
 * 初始化：dp[0][0] = triangle[0][0], dp[i][0] = dp[i-1][0], dp[i][i] = dp[i-1][i-1], i>0;
 * 方法一：空间复杂度为O(n^2)
 * 方法二：空间复杂度为O(n)
 **/

 //方法一
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>> dp(m, vector<int>(triangle[m-1].size(), 0));
        dp[0][0] = triangle[0][0];
        for(int i=1; i<m; i++){
            dp[i][0] = triangle[i][0] + dp[i-1][0];
            dp[i][i] = triangle[i][i] + dp[i-1][i-1];
        }
        for(int i=1; i<triangle.size(); i++){
            for(int j=1; j<i; j++){
                dp[i][j] = triangle[i][j] + min(dp[i-1][j], dp[i-1][j-1]);
            }
        }
        int minPath = INFINITY;
        for(int i=0; i<m; i++){
            minPath = min(minPath, dp[m-1][i]);
        }
        return minPath;
    }
};

//方法二：
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<int> dp(m, 0);
        dp[0] = triangle[0][0];
        for(int i=1; i<m; i++){
            dp[i] = triangle[i][i] + dp[i-1];
            for(int j=i-1; j>0; j--){
                dp[j] = triangle[i][j] + min(dp[j], dp[j-1]);
            }
            dp[0] = triangle[i][0] + dp[0];
        }
        int minPath = INFINITY;
        for(int i=0; i<m; i++){
            minPath = min(minPath, dp[i]);
        }
        return minPath;
    }
};