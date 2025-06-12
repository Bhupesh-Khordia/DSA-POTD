# include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-difference-between-adjacent-elements-in-a-circular-array/description/?envType=daily-question&envId=2025-06-12

class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans = INT_MIN;
        int prev = nums[0];

        for(int i = 0; i < nums.size(); i++) {
            ans = max(ans, abs(nums[i] - prev));
            prev = nums[i];
        }

        ans = max(ans, abs(prev - nums[0]));

        return ans;
    }
};
