class Solution {
    const int mod = 1e9 + 7;
public:
    // Single pass solution
    int specialTriplets(vector<int>& A) {
        int mod = 1e9 + 7, res = 0;
        unordered_map<int, int> c1, c2;
        for (int a : A) {
            if (a % 2 == 0)
                res = (res + c2[a / 2]) % mod;
            c2[a] = (c2[a] + c1[a * 2]) % mod;
            c1[a]++;
        }
        return res;
    }

    // int specialTriplets(vector<int>& nums) {
    //     unordered_map<long long, int> cnt;
    //     for(auto num : nums) cnt[num]++;

    //     int n = nums.size();
    //     long long ans = 0;
    //     unordered_map<int, int> leftCnt;
    //     leftCnt[nums[0]]++;
    //     for(int i = 1; i < n - 1; i++) {
    //         long long dbl = nums[i] * 2;
    //         int leftOptions = leftCnt[dbl];
    //         int rightOptions = (dbl == 0 ? cnt[dbl] - leftCnt[dbl] - 1 : cnt[dbl] - leftCnt[dbl]);

    //         ans = (ans + ((1LL * leftOptions * rightOptions) % mod)) % mod;

    //         leftCnt[nums[i]]++;
    //     }

    //     return (int)ans;
    // }
};
