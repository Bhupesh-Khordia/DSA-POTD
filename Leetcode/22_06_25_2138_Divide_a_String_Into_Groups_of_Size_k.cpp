// https://leetcode.com/problems/divide-a-string-into-groups-of-size-k/description/?envType=daily-question&envId=2025-06-22

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;

        int n = s.length();
        for(int i = 0; i < n; i++) {
            if(i % k == 0) {
                ans.push_back(string(1, s[i]));
            } else {
                ans[ans.size() - 1] += s[i];
            }
        }

        while(ans[ans.size() - 1].length() != k) {
            ans[ans.size() - 1] += fill;
        }

        return ans;
    }
};
