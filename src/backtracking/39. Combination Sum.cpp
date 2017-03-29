/**
 * 典型的回溯题目
 **/
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combination;
        solve(candidates, target, ans, combination, 0);
        return ans;
    }
    void solve(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combination, int begin){
        if(!target){
            ans.push_back(combination);
            return;
        }
        for(int i=begin; i<candidates.size() && candidates[i] <= target; i++){
            combination.push_back(candidates[i]);
            solve(candidates, target-candidates[i], ans, combination, i);
            combination.pop_back();
        }
    }
};