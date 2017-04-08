/**
 * 这种题目比较难，第二遍刷的时候在来总结吧
 * 题目大意：
 **/
class Solution {
public:
    unordered_map<int, bool> dp;
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal) return true;
        int sum = maxChoosableInteger * (maxChoosableInteger+1) / 2;
        if(sum < desiredTotal) return false;
        vector<bool> used(maxChoosableInteger+1, false);
        return helper(desiredTotal, used);
    }
    
    bool helper(int desiredTotal, vector<bool> used){
        if(desiredTotal <= 0) return false;
        int key = format(used);
        if(!dp[key]){
            for(int i=1; i<used.size(); i++){
                if(used[i]) continue;
                used[i] = true;
                if(!helper(desiredTotal -i, used)){
                    dp[key] = true;
                    used[i] = false;
                    return true;
                }
                used[i] = false;
            }
            dp[key] = false;
        }
        return dp[key];
    }
    
    int format(vector<bool> used){
        int ans = 0;
        for(int i=1; i<used.size(); i++){
            bool b = used[i];
            ans <<= 1;
            if(b){
                ans |= 1;
            }
        }
        return ans;
    }
};