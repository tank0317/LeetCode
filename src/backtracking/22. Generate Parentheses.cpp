/**
 * 回溯
 **/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(ans, "", 0, 0, n);
        
        return ans;
    }
    
    /**
     * n为左括号的个数
     * m为右括号的个数
     **/
    void solve(vector<string> &v, string str, int n, int m, int max){
        if(n+m == 2*max){
            v.push_back(str);
            return;
        }
        if(n<max) solve(v, str+"(", n+1, m, max);
        if(m<n) solve(v, str+")", n, m+1, max);
    }
};