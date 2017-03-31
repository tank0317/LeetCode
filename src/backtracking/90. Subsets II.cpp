/**
 * 对于含有重复数值的数组求所有子集
 * 含有重复数值的，我们要先进行排序
 **/
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        solve(nums, ans, tmp, used, 0);
        return ans;
    }
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& tmp, vector<bool> used, int begin){
        ans.push_back(tmp);
        for(int i=begin; i<nums.size(); i++){
            if(i>begin && nums[i] == nums[i-1] && !used[i]) continue;
            used[i] = true;
            tmp.push_back(nums[i]);
            solve(nums, ans, tmp, used, i+1);
            tmp.pop_back();
            used[i] = false;
        }
    }
};