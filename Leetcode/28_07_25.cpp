class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int most = 0; 
        unordered_map<int, int> mp = {{0, 1}}; 
        for (int x : nums) {
            most |= x; 
            unordered_map<int, int> tmp = mp; 
            for (auto& [k, v] : tmp) mp[x | k] += v; 
        }
        return mp[most]; 
    }
};
