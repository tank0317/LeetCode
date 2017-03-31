/**
 * 只考虑英文字母和数字
 * 空字符认为是回文，返回true
 * 注意考虑如：".,,,"这种情况。
 **/
class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0, j=s.size()-1; i<j; i++, j--){
            while(!isalnum(s[i]) && i<j) i++;
            while(!isalnum(s[j]) && i<j) j--;
            if(tolower(s[i]) != tolower(s[j])) return false; 
        }
        return true;
    }
};