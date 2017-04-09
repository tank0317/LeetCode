/**
 * 如评论最高赞所说，就好像被题目耍了一样
 * 题目描述很复杂，实际很简单的一道题目
 **/

class Solution {
public:
    int findLUSlength(string a, string b) {
        if(a.size() != b.size()){
            return max(a.size(), b.size());
        }        
        if(a == b) return -1;
        return a.size();
    }
};