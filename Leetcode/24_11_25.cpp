class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        long long curr = 0;
        for(int b : nums){
          curr = (curr * 2 + b) % 5;
          ans.push_back(curr == 0);
        }
        return ans;
    }
};
