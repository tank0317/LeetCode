/**
 * 对于不含重复数值的数组，求所有子集
 **/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(nums, ans, tmp, 0);        
        return ans;
    }
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& tmp, int begin){
        ans.push_back(tmp);
        for(int i=begin; i<nums.size(); i++){
            tmp.push_back(nums[i]);
            solve(nums, ans, tmp, i+1);
            tmp.pop_back();
        }
    }
};