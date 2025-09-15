class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> chars (brokenLetters.begin(), brokenLetters.end());
        bool curr = true;
        int ans = 0;
        for(char ch : text) {
            if(ch == ' ') {
                ans += curr;
                curr = true;
            }
            else {
                if(!curr) continue;
                if(chars.find(ch) != chars.end()) curr = false;
            }
        }
        ans+=curr;
        return ans;
    }
};
