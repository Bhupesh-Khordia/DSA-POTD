// https://leetcode.com/problems/maximum-manhattan-distance-after-k-changes/?envType=daily-question&envId=2025-06-20

class Solution {
public:
    int maxDistance(string s, int k) {
        int ans = 0;
        unordered_map<char, int> freq;
        for(int i = 0; i < s.size(); ++i){
            freq[s[i]]++;
            int diff = abs(freq['N'] - freq['S']) + abs(freq['E'] - freq['W']);
            ans = max(ans, diff + min(2*k, i+1 - diff)); // Converting one N to S (if freq['S'] > freq['N']) will result in improvement of distance by 2. 
        }
        return ans;
    }
};
