/**
 * 对于含有重复数值的数组，求所有排列方式
 * 因为含有重复数值，所以需要先对数组排序， 方便后面的处理。
 **/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        solve(nums, ans, tmp, used);
        return ans;
    }
    void solve(vector<int>& nums, vector<vector<int>>& ans, vector<int>& tmp, vector<bool>& used){
        if(tmp.size() == nums.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(used[i] || (i>0 && !used[i-1] && nums[i] == nums[i-1])) continue;
            used[i] = true;
            tmp.push_back(nums[i]);
            solve(nums, ans, tmp, used);
            tmp.pop_back();
            used[i] = false;
        }
    }
};