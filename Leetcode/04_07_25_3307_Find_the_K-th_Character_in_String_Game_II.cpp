// https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/?envType=daily-question&envId=2025-07-04

class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        k -= 1;

        long long num = k; // Use long long!
        int bits = 0;
        while (num) {
            num /= 2;
            bits++;
        }

        int res = 0;
        for (int i = 0; i < bits; i++) {
            if ((k >> i) & 1LL) { // Use 1LL for long long bit mask
                res += operations[i];
            }
        }

        return 'a' + (res % 26);
    }
};
