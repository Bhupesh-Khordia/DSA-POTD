class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size(), ans = n;
        vector<int> pre(n+1);
        map<int, int> mp;
        mp[0] = -1;
        for(int i=0; i<n; i++) pre[i+1] = (pre[i] + nums[i]) % p;
        for(int i=0; i<n; i++) {
            mp[pre[i+1] % p] = i;
            if(mp.count((pre[i+1] - pre[n] + p) % p)) {
                ans = min(ans, i - mp[(pre[i+1] - pre[n] + p) % p]);
            }
        }
        if(ans >= n) ans = -1;
        return ans;
    }
};
