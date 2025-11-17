class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int cur = 0;
        int i = 0;
        for(; i<n&&nums[i]!=1; i++){}
        i++;
        for(; i<n; i++){
            if(nums[i] == 1){
                if(cur<k) return false;
                cur = 0;
            }
            else {
                cur++;
            }
        }
        return true;
    }
};
