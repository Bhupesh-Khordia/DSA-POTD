// https://leetcode.com/problems/find-lucky-integer-in-an-array/description/?envType=daily-question&envId=2025-07-05

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int m[501] = {};
        for (auto n : arr)
            ++m[n];
        for (auto n = arr.size(); n > 0; --n)
            if (n == m[n])
                return n;
        return -1;  
    }
};
