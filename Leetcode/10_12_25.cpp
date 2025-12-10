class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        int key = complexity[0];
        int n = complexity.size();
        for (int i = 1; i < n; i++) {
            if (complexity[i] <= key) {
                return 0;
            }
        }

        int ans = 1;
        int Mod = 1000000007;
        for (int i = 2; i < n; i++) {
            ans = static_cast<long long>(ans) * i % Mod;
        }

        return ans;
    }
};
