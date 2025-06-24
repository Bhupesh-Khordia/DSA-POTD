// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/?envType=daily-question&envId=2025-06-24

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int i = -1;
        int j = 0;

        int n = nums.size();
        vector<int> ans;

        while(j < n) {
            if(nums[j] == key) {
                i = max({0, i, j - k});
                while(i <= j + k && i < n) {
                    ans.push_back(i++);
                }
            }
            j++;
        }

        return ans;
    }
};
