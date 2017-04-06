
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1) >= 0;
    }
    
    int helper(vector<int>& nums, int s, int e){
        return s == e ? nums[s] : max(nums[s] - helper(nums, s+1, e), nums[e] - helper(nums, s, e-1));
    }
};