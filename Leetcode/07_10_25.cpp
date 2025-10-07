class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> free;
        vector<int> ans(rains.size(), 1);
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < rains.size(); ++i) {
            if (rains[i] == 0) {
                free.insert(i); // mark dry day
            } else {
                int lake = rains[i];
                if (lastIndex.count(lake)) {
                    auto it = free.lower_bound(lastIndex[lake]);
                    if (it == free.end()) return {}; // no dry day 
                    ans[*it] = lake; // dry this lake
                    free.erase(it);
                }
                lastIndex[lake] = i;
                ans[i] = -1;
            }
        }

        return ans;
    }
};
