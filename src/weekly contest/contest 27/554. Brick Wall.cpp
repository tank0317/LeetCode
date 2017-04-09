class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        if(wall.size() == 0) return 0;
        unordered_map<int, int> cnt;
        int tmpSum = 0;
        for(int i=0; i<wall.size(); i++){
            tmpSum = 0;
            for(int j=0; j<wall[i].size()-1; j++){
                tmpSum += wall[i][j];
                cnt[tmpSum]++;
            }
        }
        int Max = 0;
        for(auto it = cnt.begin(); it != cnt.end(); it++){
            Max = max(Max, it->second); 
        }
        return wall.size()-Max;
    }
};