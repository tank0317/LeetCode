class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i=a.size()-1, j=b.size()-1;
        int extra = 0;
        int x, y;
        while(i>=0 || j>=0 || extra){
            x = i >= 0 ? a[i--] - '0' : 0;
            y = j >= 0 ? b[j--] - '0' : 0;
            extra = x + y + extra;
            ans = (char)('0' + extra%2) + ans;
            extra = extra/2;
        }
        return ans;
    }
};