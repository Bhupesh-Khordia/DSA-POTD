class Solution {
public:
    bool isValidCode(const string &s) {
        if (s.empty()) return false;
        for (char c : s) {
            if (!(isalnum(c) || c == '_')) {
                return false;
            }
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine,vector<bool>& isActive) {

        unordered_map<string, vector<string>> mp;
        unordered_set<string> validBusiness = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        int n = code.size();

        for (int i = 0; i < n; i++) {
            if (!isActive[i]) continue;
            if (!isValidCode(code[i])) continue;
            if (!validBusiness.count(businessLine[i])) continue;

            mp[businessLine[i]].push_back(code[i]);
        }

        vector<string> order = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        vector<string> ans;
        for (auto &o : order) {
            auto &v = mp[o];
            sort(v.begin(), v.end());
            ans.insert(ans.end(), v.begin(), v.end());
        }

        return ans;
    }
}
