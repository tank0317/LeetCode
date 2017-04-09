class Solution {
public:
    int nextGreaterElement(int n) {
        typedef long long ll;
        string s = to_string(n);
        if(!next_permutation(s.begin(), s.end())){
            return -1;
        }
        ll ans;
        sscanf(s.c_str(), "%lld", &ans);
        if(ans >= (1ll << 31)){
            return -1;
        }
        return ans;
    }
};