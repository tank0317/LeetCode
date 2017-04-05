/**
 * 三维动态规划
 * 反向更新dp[][]值
 **/
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int zeroNum = 0, oneNum = 0;
        for(auto s : strs){
            zeroNum = 0; oneNum = 0;
            for(auto c : s){
                c == '0' ? zeroNum++ : oneNum++;
            }
            
            for(int i=m; i>=zeroNum; i--){
                for(int j=n; j>=oneNum; j--){
                    if(dp[i-zeroNum][j-oneNum] + 1 > dp[i][j]){
                        dp[i][j] = dp[i-zeroNum][j-oneNum] + 1;
                    }
                }
            }
        }
        return dp[m][n];
    }
};