/**
 * 典型的回溯题目
 * 我暂时还无法总结出什么东西，再多做一些回溯的题目再说吧
 **/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(candidates, target, ans, tmp, 0);
        return ans;
    }
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int> tmp, int begin){
        if(target < 0) return ;
        else if(target == 0) ans.push_back(tmp);
        else{
            for(int i=begin; i<candidates.size(); i++){
                if(i>begin && candidates[i] == candidates[i-1]) continue;
                tmp.push_back(candidates[i]);
                solve(candidates, target-candidates[i], ans, tmp, i+1);
                tmp.pop_back();
            }
        }
    }
};