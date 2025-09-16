class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int num : nums) {
            st.push_back(num);
            while (st.size() > 1) {
                int a = st.back();
                int b = st[st.size() - 2];
                int g = gcd(a, b);
                if (g == 1) break;
                st.pop_back();
                st.pop_back();
                long long l = (1LL * a * b) / g; // LCM
                st.push_back(l);
            }
        }
        return st;
    }
    
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }
};
