class Solution {
    class DisjointSet {
        vector<int> rank, parent, size;

    public:
        DisjointSet(int n) {
            rank.resize(n + 1, 0);
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node) {
            if (node == parent[node]) {
                return node;
            }
            return parent[node] = findUPar(parent[node]);
        }
        void unionByRank(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v)
                return;
            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            } else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            } else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };

public:
    vector<int> processQueries(int c, vector<vector<int>>& conn,
                               vector<vector<int>>& que) {
                            vector<int>ans;
        DisjointSet ds(c);
        for (int i = 0; i < conn.size(); i++) {
            ds.unionByRank(conn[i][0], conn[i][1]);
        }
        unordered_map<int,priority_queue<int,vector<int>,greater<int>>>mp;
        for(int i=1;i<=c;i++){
            int p=ds.findUPar(i);
            mp[p].push(i);
        }
        vector<bool>isAvailable(c+1,true);

        for(auto &q:que){
            int type=q[0];
            if(type==2){
                int x=q[1];
                isAvailable[x]=false;
            }else{
                if(isAvailable[q[1]]){
                    ans.push_back(q[1]);
                    continue;
                }
                int x=q[1];
                int ulp_x=ds.findUPar(x);
                while(!mp[ulp_x].empty()&&!isAvailable[mp[ulp_x].top()]){
                    mp[ulp_x].pop();
                }
                if(mp[ulp_x].empty())ans.push_back(-1);
                else{
                    ans.push_back(mp[ulp_x].top());
                }
            }
        }
        
        return ans;
    }
};
