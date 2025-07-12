// https://leetcode.com/problems/the-earliest-and-latest-rounds-where-players-compete/description/?envType=daily-question&envId=2025-07-12

class Solution {
    int min_r = INT_MAX, max_r = INT_MIN;
    bool visited[27][27][27] = {};
    void dfs(int mask, int round, int i, int j, int first, int second, int l, int m, int r) {
        if (i >= j)
            dfs(mask, round + 1, 0, 27, first, second, l, m, r);
        else if ((mask & (1 << i)) == 0)
            dfs(mask, round, i + 1, j, first, second, l, m, r);
        else if ((mask & (1 << j)) == 0)
            dfs(mask, round, i, j - 1, first, second, l, m, r);
        else if (i == first && j == second) {
            min_r = min(min_r, round);
            max_r = max(max_r, round);
        }
        else if (!visited[l][m][r]) {
            visited[l][m][r] = true;
            if (i != first && i != second)
                dfs(mask ^ (1 << i), round, i + 1, j - 1, first, second, 
                    l - (i < first), m - (i > first && i < second), r - (i > second));
            if (j != first && j != second)
                dfs(mask ^ (1 << j), round, i + 1, j - 1, first, second,
                    l - (j < first), m - (j > first && j < second), r - (j > second));
        }
    }
public:
    vector<int> earliestAndLatest(int n, int first, int second) {
    dfs((1 << n) - 1, 1, 0, 27, first - 1, second - 1, first - 1, second - first - 1, n - second);
    return { min_r, max_r };
    }
};
