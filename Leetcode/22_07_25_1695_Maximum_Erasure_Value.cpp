// https://leetcode.com/problems/maximum-erasure-value/description/?envType=daily-question&envId=2025-07-22

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // Find unique elements subarray with largest sum
        int l = 0, r = 0, n = nums.size(), sum = 0;
        int ans = 0;
        unordered_set<int> ele;

        while(r < n) {
            sum += nums[r];
            while(ele.find(nums[r]) != ele.end()) {
                sum -= nums[l];
                ele.erase(nums[l]);
                l++;
            }
            ele.insert(nums[r]);

            ans = max(ans, sum);
            r++;
        }

        return ans;
    }
};
