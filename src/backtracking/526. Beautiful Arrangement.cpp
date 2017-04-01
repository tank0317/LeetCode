/**
 * 回溯
 **/
class Solution {
public:
    int count = 0;
    int countArrangement(int N) {
        vector<int> used(N+1, 0);
        solve(N, 1, used);
        return count;
    }
    void solve(int N, int pos, vector<int> used){
        if(pos > N){
            count++;
            return;
        }
        for(int i=1; i<=N; i++){
            if(used[i] == 0 && (i%pos == 0 || pos%i == 0)){
                used[i] = 1;
                solve(N, pos+1, used);
                used[i] = 0;
            }
        }
    }
};