// https://leetcode.com/problems/count-the-number-of-arrays-with-k-matching-adjacent-elements/?envType=daily-question&envId=2025-06-17

class Solution {
private:
    const int MOD = 1e9 + 7;

    long long modpow(long long base, long long exp) {
        long long res = 1;
        while (exp > 0) {
            if (exp % 2 == 1) res = res * base % MOD;
            base = base * base % MOD;
            exp /= 2;
        }
        return res;
    }

    // Modular inverse using Fermat's Little Theorem
    
    // Fermat's Little Theorem -->
    // if (p is prime and a % p != 0)
    //     then (a^(p - 1)) % p == 1

    long long modinv(long long a) {
        return modpow(a, MOD - 2);
    }

    // Compute nCr modulo MOD
    long long nCr(int n, int r) {
        if (r < 0 || r > n) return 0;

        long long num = 1, den = 1;
        for (int i = 1; i <= r; ++i) {
            num = num * (n - i + 1) % MOD;
            den = den * i % MOD;
        }
        return num * modinv(den) % MOD;
    }

public:
    int countGoodArrays(int n, int m, int k) {
        // Ans is ncr(n-1, k) * m * (m - 1) ^ (n - k - 1)
        // choose k positions to be equal to previous element from last n - 1 elements
        // For first element - m choices
        // For other elements - if it is tagged equal then 1 choice else m - 1 choices (must not be equal)

        long long choose = nCr(n - 1, k);
        long long pow_term = modpow(m - 1, n - 1 - k);
        return m * choose % MOD * pow_term % MOD;
    }
};
