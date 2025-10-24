class Solution {
public:
    bool isBeautiful(int x) {
        int cnt[10] = {0};
        while (x > 0) {
            int d = x % 10;
            if (d == 0) return false; // 0 can never be balanced
            cnt[d]++;
            x /= 10;
        }
        for (int d = 1; d <= 9; d++) {
            if (cnt[d] > 0 && cnt[d] != d)
                return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        int candidate = n + 1;
        while (true) {
            if (isBeautiful(candidate))
                return candidate;
            candidate++;
        }
    }
};
