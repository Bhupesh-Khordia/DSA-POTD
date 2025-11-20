class Solution {
public:
    static bool cmp(const vector<int>& A, const vector<int>& B) {
        if (A[1] != B[1]) return A[1] < B[1]; 
        return A[0] > B[0];                  
    }
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int p1 = -1, p2 = -1; 
        int ans = 0;
        for (auto &it : intervals) {
            int L = it[0], R = it[1];
            bool has1 = (p1 >= L && p1 <= R);
            bool has2 = (p2 >= L && p2 <= R);
            if (has1 && has2) {
                continue;
            }
            else if (!has1 && !has2) {

                ans += 2;
                p1 = R - 1;
                p2 = R;
            }
            else {

                ans += 1;
                if (!has2) {
                    p2 = R;
                } else {
                    p1 = p2;
                    p2 = R;
                }
            }
        }
        return ans;
    }
};
