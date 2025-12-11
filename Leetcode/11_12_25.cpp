class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& b) {
        pair<int, int> x[n+9], y[n+9];
        for (int i=0; i<=n; i++) x[i]=y[i]={1e9, -1e9};
        for (auto it:b) {
            x[it[0]].first=min(x[it[0]].first, it[1]);
            x[it[0]].second=max(x[it[0]].second, it[1]);
            y[it[1]].first=min(y[it[1]].first, it[0]);
            y[it[1]].second=max(y[it[1]].second, it[0]);
        }
        int ans=0;
        for (auto it:b) {
            if (x[it[0]].first < it[1] && 
                x[it[0]].second > it[1] && 
                y[it[1]].first < it[0] && 
                y[it[1]].second > it[0]) {
                ans++;
            }
        }
        return ans;
    }
};
