// https://leetcode.com/problems/longest-harmonious-subsequence/description/?envType=daily-question&envId=2025-06-30

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for(auto num: nums) cnt[num]++;

        int ans = 0;
        for(auto it : cnt) {
            if(cnt.count(it.first + 1) > 0) {
                ans = max(ans, it.second + cnt[it.first + 1]);
            }
        }

        return ans;
    }
};
