class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = n - 1, j = n - 2, k = n - 3;

        while (k >= 0) {
            int sum = nums[j] + nums[k];
            
            if (sum > nums[i])
                return sum + nums[i];

            i--;
            j--;
            k--;
        }

        return 0;
    }
};
