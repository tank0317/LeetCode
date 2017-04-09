/**
 * 主要是reverse()库函数的使用
 * reverse()的实现方式类似如下，这里使用下标访问字符串中的字符
 * reverse(int i, int j){
 *     while(1){
 *         if(i == j || i == --j)
 *             return;
 *         else
 *             swap(s[i++], s[j]);
 *     }    
 * }
 **/

class Solution {
public:
    string reverseStr(string s, int k) {
        if(s.size() == 0) return s;
        if(k == 1) return s;
        auto it = s.begin();
        for(; it+2*k < s.end(); it += 2*k){
            reverse(it, it+k);
        }
        if(it + k <= s.end()) reverse(it, it+k);
        else reverse(it, s.end());
        return s;
    }
};