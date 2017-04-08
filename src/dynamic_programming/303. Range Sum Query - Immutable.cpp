class NumArray {
public:
    NumArray(vector<int> nums) : pnums(nums.size(), 0) {
        partial_sum(nums.begin(), nums.end(), pnums.begin());
    }
    
    int sumRange(int i, int j) {
        if(i == 0) return pnums[j];
        return pnums[j] - pnums[i-1];
    }
private:
    vector<int> pnums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */