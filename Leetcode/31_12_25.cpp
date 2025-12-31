class Solution {
private:
    int rows, cols;
    vector<vector<int>> grid, visited;

    int delrow[4] = {1, -1, 0, 0};
    int delcol[4] = {0, 0, 1, -1};

    bool dfs(int r, int c) {
        if (r==rows-1) return true;

        visited[r][c] = 1;

        for (int i = 0; i < 4; i++) {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];

            if (nrow >= 0 && nrow < rows && ncol >= 0 && ncol < cols) {
                if (grid[nrow][ncol] == 0 && visited[nrow][ncol] == 0) {
                    if (dfs(nrow, ncol)) return true;
                }
            }
        }
        return false;
    }

    bool canCross(int day, vector<vector<int>>& cells) {
        grid.assign(rows, vector<int>(cols, 0));
        visited.assign(rows, vector<int>(cols, 0));

        for (int i = 0; i < day; i++) {
            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;
        }

        for (int c = 0; c < cols; c++) {
            if (grid[0][c] == 0 && visited[0][c] == 0) {
                if (dfs(0, c)) return true;
            }
        }
        return false;
    }

public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        rows = row;
        cols = col;

        int left = 0, right = cells.size();
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canCross(mid, cells)) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return ans;
    }
};
