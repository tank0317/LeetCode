class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        //如果入口和出口放置障碍物则没有可用路径
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1]) return 0;
        vector<int> dp(n, 0);
        //上面已经排除入口放置障碍物的情况，所以这里dp[0] = 1;
        dp[0] = 1;
        //初始化dp[]数组
        for(int i=1; i<n; i++){
            if(obstacleGrid[0][i] == 1) dp[i] = 0;
            else dp[i] = dp[i-1];
        }
        for(int i=1; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                }else if(j>0){
                    dp[j] = dp[j] + dp[j-1];
                }
            }
        }
        return dp[n-1];
    }
};