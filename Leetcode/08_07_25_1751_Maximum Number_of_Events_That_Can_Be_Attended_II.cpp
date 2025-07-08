// https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/description/?envType=daily-question&envId=2025-07-08

class Solution {
private:
    int findNext(const vector<vector<int>>& events, int currEnd) {
        int left = 0, right = events.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (events[mid][0] > currEnd) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left; // index of the first event that starts after currEnd
    }

    int solve(vector<vector<int>>& events, int k, int index, vector<vector<int>> &dp) {
        if(index == events.size() || k == 0) return 0;

        if(dp[k][index] != -1) return dp[k][index];

        // Include 
        int include = events[index][2] + solve(events, k - 1, findNext(events, events[index][1]), dp);

        // Exclude 
        int exclude = solve(events, k, index + 1, dp);

        return dp[k][index] = max(include, exclude);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {
        sort(events.begin(), events.end());
        vector<vector<int>> dp (k + 1, vector<int> (events.size(), -1));
        return solve(events, k, 0, dp);
    }
};
