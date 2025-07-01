// https://leetcode.com/problems/find-the-original-typed-string-i/description/?envType=daily-question&envId=2025-07-01

class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        for(int i = 1; i < word.length(); i++) {
            if(word[i] == word[i - 1]) ans++;
        }
        return ans;
    }
};
