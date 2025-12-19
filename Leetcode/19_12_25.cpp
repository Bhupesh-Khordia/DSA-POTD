class Solution {

void dfs(int u, unordered_map<int, vector<int>>& g, unordered_map<int, bool>& vis, vector<bool>& has_secret){
    vis[u] = true;
    has_secret[u] = true;

    for (auto& c : g[u])
        if (!vis[c])
            dfs(c, g, vis, has_secret);
}
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        int len = 1e5+5, m = (int)meetings.size();
        
        vector<bool> has_secret(n);
        vector<unordered_map<int, vector<int>>> v(len);

        has_secret[0] = true;
        v[0][firstPerson].push_back(0), v[0][0].push_back(firstPerson);

        for (int i = 0; i < m; i++){
            v[meetings[i][2]][meetings[i][1]].push_back(meetings[i][0]);
            v[meetings[i][2]][meetings[i][0]].push_back(meetings[i][1]);
        }

        for (int i = 0; i < len; i++){
            unordered_map<int, bool> vis;
            for (auto& g : v[i])
                if (has_secret[g.first] && !vis[g.first])
                    dfs(g.first, v[i], vis, has_secret);
        }

        vector<int> res;
        for (int i = 0; i < n; i++)
            if (has_secret[i])
                res.push_back(i);

        return res;
    }
};
