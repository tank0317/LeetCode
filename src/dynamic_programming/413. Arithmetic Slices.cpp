/**
 * 主要是发现规律，实现过程很简单
 * 比如序列 【1 2 3】Arithmetic Slices（AS)为1，增加一个数字【1 2 3 4】AS为1+2
 * 再增加一个数字【1 2 3 4 5】AS为1+2+3，增加的值依次加1
 * 当增加一个数字不构成AS时，【1 2 3 4 5 7】 则增加的值从零重新开始 AS = 1+2+3+0
 **/
 
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int tmp = 0; 
        int sum = 0;
        for(int i=2; i<A.size(); i++){
            if(A[i] - A[i-1] == A[i-1] - A[i-2]){
                tmp += 1;
                sum += tmp;
            }else{
                tmp = 0;
            }
        }
        return sum;
    }
};