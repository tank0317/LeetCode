class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid1 = (left+right)/2;
            int mid2 = mid1+1;
            if(nums[mid1] < nums[mid2]) left = mid2;
            else right = mid1;
        }
        return right; //return left or right 
    }
};
