class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if(x>=0) std::reverse(s.begin(), s.end());
        else std::reverse(s.begin()+1, s.end());
        long long ans = stoll(s);
        if(abs(ans) > (1ll << 31)) return 0;
        return (int)ans;
    }
};