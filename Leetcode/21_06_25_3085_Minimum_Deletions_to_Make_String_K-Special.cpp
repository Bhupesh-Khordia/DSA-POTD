// https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/description/?envType=daily-question&envId=2025-06-21

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> cnt;
        for(auto ch : word) cnt[ch]++;

        vector<int> freqs;
        for (auto it : cnt)
            freqs.push_back(it.second);

        sort(freqs.begin(), freqs.end());

        int ans = INT_MAX;
        for(int i = 0; i < freqs.size(); i++) {
            int minFreq = freqs[i];
            int deletions = 0;
            for(int i = 0; i < freqs.size(); i++) {
                if(freqs[i] < minFreq) deletions += freqs[i];
                else if(freqs[i] > minFreq + k) deletions += freqs[i] - (minFreq + k);
            }
            ans = min(ans, deletions);
        }

        return ans;
    }
};
