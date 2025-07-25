// https://leetcode.com/problems/maximum-unique-subarray-sum-after-deletion/description/?envType=daily-question&envId=2025-07-25

class Solution {
public:
    int maxSum(vector<int>& nums) {
        bool allNegative = true;
        int maxVal = INT_MIN;

        for (int n : nums) {
            if (n >= 0) allNegative = false;
            if (n > maxVal) maxVal = n;
        }
        if (allNegative) return maxVal;

        unordered_set<int> unique(nums.begin(), nums.end());

        int sum = 0;
        for (int val : unique) {
            if (val > 0) sum += val;
        }

        return sum;
    }
};
