/**
 * 整个思路是，只需要求出所有以a, b, c ... z为结尾的子串的数量和即所有unique subtrings。
 * 然后我们用一个int数组来分别存储26个英文字母为结尾的子串的数量。
 * 比如对于“abcd" 以a为结尾的子串数量为1，
 *                以b为结尾的子串数量为2，
 *                以c为结尾的子串数量为3，
 *                以d为结尾的子串数量为4
 *                其他英文字母结尾的子串数量为0
 * 所以总的unique substring 的数量为1 + 2 + 3 + 4 + 0 + ... + 0 = 10
 * 而我们可以通过一次遍历字符串而得到所有26个英文字母结尾的子串数量。
 **/

class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if(p.size() == 0) return 0;
        vector<int> cnt(26, 0);
        cnt[p[0]-'a'] = 1;
        int count = 1;
        for(int i=1; i<p.size(); i++){
            if(p[i] - p[i-1] == 1 || p[i-1] - p[i] == 25){
                count++;
            }else{
                count = 1;
            }
            cnt[p[i] - 'a'] = max(count, cnt[p[i] - 'a']);
        }
        count = 0;
        for(int x : cnt){
            count += x;
        }
        return count;
    }
};