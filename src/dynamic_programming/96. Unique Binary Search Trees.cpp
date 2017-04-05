/**
 * 这道题目主要是状态转移方程的建立
 * 列出状态转移方程后，实现过程非常简单，代码量很少
 * G[n]看做是长度为n的序列能够组合出的BST数量
 * F(i, n)看做是长度为n的序列，以i为根节点的BST的数量
 * 所以G[n] = F(1, n) + F(2, n) + ... + F(i, n) + ... + F(n, n)
 * 另外F(i, n) = G(i-1) * G(n-i) , 1 <= i <= n; 表示以i为根节点的BST数量，
 * 即序列长度为i-1的左子树BST数量，和序列长度为n-i的右子树BST数量的乘积
 * 所以G(n) = G(0)*G(n-1) + G(1)*G(n-2) + ... + G(n-1)*G(0)
 **/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<i; j++){
                dp[i] += dp[j] * dp[i-1-j];
            }
        }
        return dp[n];
    }
};