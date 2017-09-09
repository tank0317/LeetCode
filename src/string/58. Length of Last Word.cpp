class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size() - 1;
        int j;
        while(i>=0 && s[i] == ' ') i--;
        if(i == -1) return 0;
        j = i;
        while(j>=0 && s[j] != ' ') j--;
        return i-j;
    }
};