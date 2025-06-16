// https://leetcode.com/problems/maximum-difference-between-increasing-elements/description/?envType=daily-question&envId=2025-06-16

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int prevMin = nums[0];
        int ans = INT_MIN;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] >= prevMin) {
                ans = max(ans, nums[i] - prevMin);
            }
            prevMin = min(prevMin, nums[i]);
        }

        return ans <= 0 ? -1 : ans;
    }
};
