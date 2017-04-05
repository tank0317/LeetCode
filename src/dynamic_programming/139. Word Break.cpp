/**
 * 单序列动态规划问题
 **/
class Solution {
public:
    //得到字典中word的最大长度
    int maxLength(vector<string>& wordDict){
        int n = wordDict.size();
        int maxLen = 0;
        for(int i=0; i<n; i++){
            maxLen = max((int)wordDict[i].size(), maxLen);
        }
        return maxLen;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true; //初始化dp[0]为true, 为后面提供方便
        int maxLen = maxLength(wordDict);
        set<string> S(wordDict.begin(), wordDict.end());
        for(int i=1; i<=n; i++){ //i表示字符序列中第i个字符，从1到n
            for(int j=1; j<=i && j<=maxLen; j++){
                //之所以substr(i-j, j)，而不是substr(i-j+1, j), 因为i是从1开始的。
                if(dp[i-j] && S.find(s.substr(i-j, j)) != S.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};