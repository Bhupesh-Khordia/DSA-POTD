class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long>org(n, 0);
        vector<long long>one(n, 0);
        for(int i = 0; i < n; ++i)
        {
            org[i] = (i>0?org[i-1]:0)+prices[i]*1LL*strategy[i];
            one[i] = (i>0?one[i-1]:0)+prices[i]*1LL;
        }
        long long rt = org.back();
        for(int i = 0; i < n-k+1; ++i)
        {
            rt = max(rt, (i>0?org[i-1]:0) + (one[i+k-1]-one[i+k/2-1]) + (i+k>=n?0:org.back()-org[i+k-1]));
        }

        return rt;
    }
};
// 5 9 9
