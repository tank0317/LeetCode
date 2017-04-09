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
    string reverseWords(string s) {
        string substr = "";
        string ans = "";
        for(char c : s){
            if(c != ' '){
                substr += c;
            }else{
                reverse(substr.begin(), substr.end());
                ans += substr + ' ';
                substr = "";
            }
        } 
        reverse(substr.begin(), substr.end());
        ans += substr;
        return ans;
    }
};