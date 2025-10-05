class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& heights, vector<vector<int>>& visited, int r, int c) {
        visited[r][c] = 1;

        for (auto &dir : directions) {
            int nr = r + dir[0];
            int nc = c + dir[1];
            // Check bounds and if next cell is higher or equal
            if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                !visited[nr][nc] && heights[nr][nc] >= heights[r][c]) {
                dfs(heights, visited, nr, nc);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));

        // DFS from Pacific Ocean (top row + left column)
        for (int i = 0; i < m; ++i) dfs(heights, pacific, i, 0);
        for (int j = 0; j < n; ++j) dfs(heights, pacific, 0, j);

        // DFS from Atlantic Ocean (bottom row + right column)
        for (int i = 0; i < m; ++i) dfs(heights, atlantic, i, n - 1);
        for (int j = 0; j < n; ++j) dfs(heights, atlantic, m - 1, j);

        // Find common cells
        vector<vector<int>> result;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }
};
