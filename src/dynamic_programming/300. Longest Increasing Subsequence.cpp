/**
 * 动态规划题目
 * 使用固定套路解答
 **/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int maxLen = 0;
        vector<int> len(nums.size(), 1);
        for(int i=0; i<nums.size(); i++){
            len[i] = 1;
            for(int j=0; j<i; j++){
                if(nums[j] < nums[i] && len[j] + 1 > len[i])
                    len[i] = len[j] + 1;
            }
            maxLen = max(maxLen, len[i]);
        }
        return maxLen;
    }
};