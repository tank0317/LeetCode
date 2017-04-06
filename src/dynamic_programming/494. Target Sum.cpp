class Solution {
public:
    int count = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
        helper(nums, S, 0);
        return count;
    }
    
    void helper(vector<int>& nums, int S, int pos){
        if(pos == nums.size()) {
            if(S ==0) count++;
            return;
        }
        helper(nums, S-nums[pos], pos+1);
        helper(nums, S+nums[pos], pos+1);
    }
};