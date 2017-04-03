/**
 * 二维动态规划题目
 * 方法一使用典型动态规划套路解答
 * 方法二思路与方法一一样，但是优化了空间复杂度。
 **/

 //方法一
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, grid[0][0]));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[i].size(); j++){
                if(i==0 && j==0) dp[i][j] == grid[i][j];
                else dp[i][j] = grid[i][j] + min(i>0 ? dp[i-1][j] : INFINITY, j>0 ? dp[i][j-1] : INFINITY);
            }
        }
        return dp[m-1][n-1];
    }
};

//方法二
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp(n,  grid[0][0]); //使用一维vector存放中间量
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i==0 && j==0) dp[j] == grid[i][j];
                else dp[j] = grid[i][j] + min(i>0 ? dp[j] : INFINITY, j>0 ? dp[j-1] : INFINITY);
            }
        }
        return dp[n-1];
    }
};