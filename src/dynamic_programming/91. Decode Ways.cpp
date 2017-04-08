/**
 * 题目确实完全靠自己做出来了，但是许多细节出错，导致最后调试浪费很长时间，以后应当避免
 * 我们用[i, end]表示字符串从第i个位置开始，到字符串结尾的子串。
 * 状态：f(i)表示[i, end]的子串有多少种decode方式([i, end])
 * 状态方程：分析，对于(i, end)子串来说， 
 * case 1, 如果第i个数字能够解码（即第i个字符不为0），
 * 那么这种情况只需要看[i+1, end]子串有多少种解码方式，即f(i+1)，
 * case 2, 如果[i, i+1]也能够完成解码（即10 <= [i, i+1] <= 26])，这种情况
 * 只需要看[i+2, end]的子串有多少种解码方式，即f(i+2)。
 * 所以f(i) = 0, case 1, case 2都不满足
 *          = f(i+1), 满足case 1，不满足case 2
 *          = f(i+1) + f(i+2), case 1, case 2都满足
 * 初始化：f(end) = 1; 
 *         f(end - 1) = 0, 不满足case 1;
 *                    = 1, 满足 case 1;
 **/

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0) return 0;
        int len = s.size();
        vector<int> dp(len+1, 0);
        if(s[len-1] - '0') dp[len-1] = 1;
        dp[len] = 1;
        for(int i=len-2; i>=0; i--){
            if(s[i] != '0') {
                dp[i] = dp[i+1];
                if(s[i] == '1' || (s[i] == '2' && s[i+1]-'0' < 7)) dp[i] += dp[i+2];
            }
        }
        return dp[0];
    }
};