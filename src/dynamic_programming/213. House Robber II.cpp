/**
 * 由于头尾相连，如果抢劫了house 0 就不能抢劫 house n-1， 反之亦然
 * 所以我们可以分成两部分，house 0 ~ n-2 和 house 1 ~ n-1; 
 * 然后分别求这两部分可能抢劫的最大值
 * 最后取两者max
 **/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        return max(helper(nums, 0, n-2), helper(nums, 1, n-1));
    }
    
    int helper(vector<int>& nums, int l, int r){
        int pre=0, cur=0;
        for(int i=l; i<=r; i++){
            int tmp = max(pre+nums[i], cur);
            pre = cur;
            cur = tmp;
        }
        return cur;
    }
};