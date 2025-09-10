#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();

        // Store user->languages as set for quick lookup
        vector<unordered_set<int>> knows(m + 1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i]) {
                knows[i + 1].insert(lang);
            }
        }

        // Find users that are in friendships without common language
        unordered_set<int> need;
        for (auto &f : friendships) {
            int u = f[0], v = f[1];
            bool ok = false;
            for (int lang : knows[u]) {
                if (knows[v].count(lang)) {
                    ok = true;
                    break;
                }
            }
            if (!ok) {
                need.insert(u);
                need.insert(v);
            }
        }

        // If no one needs teaching
        if (need.empty()) return 0;

        int ans = INT_MAX;
        // Try teaching each language
        for (int lang = 1; lang <= n; lang++) {
            int cnt = 0;
            for (int user : need) {
                if (!knows[user].count(lang)) {
                    cnt++;
                }
            }
            ans = min(ans, cnt);
        }

        return ans;
    }
};
