class Solution {
    unordered_map<string, unordered_set<char>> h;
    unordered_map<string, bool> memo;

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.length();
        for (string& s : allowed) {
            h[s.substr(0, 2)].insert(s[2]);
        }
        return f(0, "", bottom, n);
    }

    bool f(int index, string curr, string bottom, int n) {
        if (n == 1) return true;

        if (index == 0 && memo.count(bottom)) {
            return memo[bottom];
        }

        if (index == n - 1) {
            return memo[bottom] = f(0, "", curr, n - 1);
        }

        bool ok = true;
        string sub = bottom.substr(index, 2);

        if (h.count(sub) == 0) return false;

        for (char c : h[sub]) {
            if (f(index + 1, curr + c, bottom, n)) {
                return true;
            }
        }

        return false;
    }
};
