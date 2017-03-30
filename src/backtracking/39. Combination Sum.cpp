/**
 * 典型的回溯题目
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
        if(target == 0) ans.push_back(tmp);
        for(int i=begin; i<candidates.size() && candidates[i] <= target; i++){
            if(i>begin && candidates[i] == candidates[i-1]) continue;
            tmp.push_back(candidates[i]);
            solve(candidates, target-candidates[i], ans, tmp, i+1);
            tmp.pop_back();
        }
    }
};