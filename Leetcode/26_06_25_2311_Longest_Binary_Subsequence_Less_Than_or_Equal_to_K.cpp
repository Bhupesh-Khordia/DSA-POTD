// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/description/?envType=daily-question&envId=2025-06-26

class Solution {
private:
    int solveDP(string s, int k, int ind, int currNo, vector<vector<int>> &dp) {
        if(ind < 0) return 0;

        if(dp[ind][currNo] != -1) return dp[ind][currNo];

        int ans = INT_MIN;
        // Include

        // long long newNo = currNo + ((s[ind] - '0') * (pow(2, s.length() - ind - 1)));
        long long newNo = currNo + ((s[ind] - '0') * (1LL << (s.length() - ind - 1)));
        if(newNo <= (long long)k) {
            ans = max(ans, 1 + solveDP(s, k, ind - 1, newNo, dp));
        }

        // Exlude 
        ans = max(ans, solveDP(s, k, ind - 1, currNo, dp));

        return dp[ind][currNo] = ans;
    }
public:
    int longestSubsequence(string s, int k) {
        // MLE

        // vector<vector<int>> dp (s.length(), vector<int> (k + 1, -1));
        // return solveDP(s, k, s.length() - 1, 0, dp);


        int val = 0, cnt = 0, pow = 1;
        for (int i = s.size() - 1; i >= 0 && val + pow <= k; --i) {
            if (s[i] == '1') {
                ++cnt;
                val += pow;
            }
            pow <<= 1;
        }
        return count(begin(s), end(s), '0') + cnt;
    }
};
