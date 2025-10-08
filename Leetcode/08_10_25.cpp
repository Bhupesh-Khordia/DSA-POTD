class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());

        vector<int> ans;
        for(int i = 0; i < spells.size(); i++) {
            auto it = lower_bound(potions.begin(), potions.end(), success % spells[i] == 0 ? success / spells[i] : (success / spells[i]) + 1);
            ans.push_back(potions.end() - it);
        }

        return ans;
    }
};
