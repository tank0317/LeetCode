/**
 * 根据提示，设f(k)表示长度为k的数字中，没有重复数字的值的个数
 * 并且有f(1) = 10; f(2) = 9 * 9; f(3) = 9 * 9 * 8
 * f(k) = 9 * 9 * 8 * 7 * ... * (10-k+1);  
 * 而且当数字长度大于10的时候肯定有重复数字
 * 所以 ans = f(1) + f(2) + ... + f(n)
 **/
 
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 0;
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