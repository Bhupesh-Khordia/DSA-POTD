class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> res(nums.size()), closest(30);
        for (int i = nums.size() - 1; i >= 0; --i) {
            for (int b = 0; b < 30; ++b)
                if (nums[i] & (1 << b))
                    closest[b] = i;
            res[i] = max(1, *max_element(begin(closest), end(closest)) - i + 1);
        }
        return res;
    }   
};
