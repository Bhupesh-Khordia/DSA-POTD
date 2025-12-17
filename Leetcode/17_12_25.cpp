class Solution {
public:
    int n;
    // threee fieds are changing
    long long t[1001][501][3];

    long long solve(int index, int k, int tranCase, vector<int>& prices) {
        if (index == n) {
            if (tranCase == 0) {
                return 0;
            }
            return INT_MIN;
        }
        if (t[index][k][tranCase] != INT_MIN) {
            return t[index][k][tranCase];
        }
        long long take = INT_MIN;
        long long notake;

        notake = solve(index + 1, k, tranCase, prices); // skip to next

        // now we have to chheck every time thst we arw all0wed to the trans
        if (k > 0) {

            if (tranCase == 1) {
                // then we have to sell and complete the trans, so send 0
                take = prices[index] + solve(index + 1, k - 1, 0, prices);
            } else if (tranCase == 2) {
                // then we have to buy this to complete the short sell transx
                take = -prices[index] + solve(index + 1, k - 1, 0, prices);
            } else {
                // we have came to new tranx
                // we have to make sure to choose best of take and not take
                // and dont decrease the k as trans is not completed
                take = max(-prices[index] + solve(index + 1, k, 1, prices),
                           prices[index] + solve(index + 1, k, 2, prices));
            }
        }
        return t[index][k][tranCase] = max(take, notake);
    }
    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        // so the thing is we have to take care of
        // 1. first buy and sell
        // 2. first short sell and then buy

        // and this comes with 3 cases
        // case = 0 -> that we have started fresh transaction , buy-sell already satisfied so go for new transaction 
        // case = 1 -> that we have already buy means -prices[index] and we have to look for sell option 
        // case = 2 -> that we have already short sell the stock now only buy is the option

        // starting with fresh trans case = 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= k; j++) {
                for (int l = 0; l < 3; l++) {
                    t[i][j][l] = INT_MIN;
                }
            }
        }
        return solve(0, k, 0, prices); // (index,k,case value,prices)
    }
};
