class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int x = 0, y = 0;
        int m = mat.size(), n = mat[0].size();
        vector<int> ans;
        bool flag = true; // true if going bottom to top
        while(!(x == m - 1 && y == n - 1)) {
            ans.push_back(mat[x][y]);
            if(flag) {
                if(x - 1 >= 0 && y + 1 < n) {
                    x--;
                    y++;
                } else {
                    flag = false;
                    if(y + 1 < n) y++;
                    else x++;
                }
            } else {
                if(x + 1 < m && y - 1 >= 0) {
                    x++;
                    y--;
                } else {
                    flag = true;
                    if(x + 1 < m) x++;
                    else y++;
                }
            }
        }
        ans.push_back(mat[x][y]);
        return ans;
    }
};
