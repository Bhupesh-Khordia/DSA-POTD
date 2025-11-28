class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        int result = 0;
        
        function<long long(int,int)> dfs = [&](int node, int parent) {
            long long sum = values[node];
            for (int nei : adj[node]) {
                if (nei == parent) continue;
                sum += dfs(nei, node);
            }
            if (sum % k == 0) {
                result++; // this subtree can form a component
                return 0LL; // cut here, don't propagate sum upward
            }
            return sum;
        };
        
        dfs(0, -1);
        return result;
    }
};
