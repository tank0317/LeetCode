/**
 * 题目提示的已经很明确了
 * 1的值的出现是有规律的，对于关键值2^i为起点, 
 * 之后的2^i个数字的都是对之前2^i个数字的1的个数加1
 * 对于8来说
 * 二进制    num    关键值    1的个数
 * 0 0 0 0    0                  0
 * 0 0 0 1    1 |    2^0         1
 * 0 0 1 0    2  |   2^1         1
 * 0 0 1 1    3  |               2
 * 0 1 0 0    4   |  2^2         1
 * 0 1 0 1    5   |              2 
 * 0 1 1 0    6   |              2
 * 0 1 1 1    7   |              3
 * 1 0 0 0    8    | 2^3         1
 **/
 
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1, 0);
        for(int i=0; i<=(int)log2(num); i++){
            int start = pow(2, i);
            int n = start;
            for(int j=0; j<n && start+j<=num; j++){
                dp[start + j] = dp[j] + 1;
            }
        }
        return dp;
    }
};