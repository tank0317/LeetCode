class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        int ans = 10;
        int uni = 9;
        int nums = 9;
        while(n-- > 1 && nums > 0){
            uni = uni * nums;
            ans += uni;
            nums--;
        }
        return ans;
    }
};