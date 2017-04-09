/**
 * 与521. Longest Uncommon Subsequence I类似
 * 由于数量小，所以使用两层循环直接暴力一一比较
 * 主要是s1IsSubS2()函数的实现，判断s1是否是s2的sub sequence
 **/
bool mycom(string& a, string& b){
    return a.size() > b.size();
}

bool s1IsSubS2(string s1, string s2){
    int i = 0;
    for(char c : s2){
        if(i<s1.size() && s1[i] == c) i++;
    }
    return i == s1.size();
}

class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        sort(strs.begin(), strs.end(), mycom);
        for(int i=0; i<strs.size(); i++){
            int j = 0;
            for(; j<strs.size(); j++){
                if(i!=j && s1IsSubS2(strs[i], strs[j])) break; 
            }
            if(j == strs.size()) return strs[i].size();
        }
        return -1;
    }

};