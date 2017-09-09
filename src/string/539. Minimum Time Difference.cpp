/**
 * stringstream的使用
 * 非常好用
 **/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(), timePoints.end());
        int mini = diffTime(timePoints[0], timePoints[n-1]);
        for(int i=1; i<timePoints.size(); i++){
            int tmp = diffTime(timePoints[i], timePoints[i-1]);
            mini = min(mini, tmp);
        }
        return mini;
    }
    
    int diffTime(string time1, string time2){
        int h1, m1, h2, m2;
        stringstream str;
        char c;
        str << time1;
        str >> h1 >> c >> m1;
        str.clear();
        str << time2;
        str >> h2 >> c >> m2;
        int t1 = h1*60+m1;
        int t2 = h2*60+m2;
        return min((t1+1440-t2)%1440, (t2+1440-t1)%1440);
    }
};