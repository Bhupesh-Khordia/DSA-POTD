class Solution {
    long long stepsSum(long long n) {
        if (n <= 0) return 0;
        long long total = 0;
        long long step = 1;
        long long start = 1;
        while (start <= n) {
            long long end = min(n, start * 4 - 1);
            long long count = end - start + 1;
            total += count * step;
            step++;
            start *= 4;
        }
        return total;
    }
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans = 0;
        for(auto i : queries) {
            int l = i[0], r = i[1];
            long long totalSteps = stepsSum(r) - stepsSum(l - 1);
            ans += (totalSteps + 1) / 2;
        }
        return ans;
    }
};
