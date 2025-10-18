class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int mini = nums[0] - k;
        int maxi = nums[n-1] + k;

        unordered_set<int> result;
        int curr = mini;
        for(int i=0;i<nums.size();i++) {
            curr = max(curr, nums[i]-k);
            curr = min(nums[i]+k, curr);

            result.insert(curr);
            curr++;
        }

        return result.size();
    }
};
