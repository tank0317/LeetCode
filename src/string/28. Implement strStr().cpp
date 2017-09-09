class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int i=0;
        while(i<haystack.size()){
            int j=0;
            while(j<needle.size()){
                if(i+j == haystack.size()) return -1;
                if(needle[j] != haystack[i+j]) break;
                j++;
            }
            if(j == needle.size()) return i;
            i++;
        }
        return -1;
    }
};