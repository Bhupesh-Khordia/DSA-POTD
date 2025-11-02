class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        // Step 1: Initialize grid
        vector<vector<char>> grid(m, vector<char>(n, '.'));

        // Step 2: Place walls
        for (const auto& wall : walls) {
            grid[wall[0]][wall[1]] = 'W';
        }

        // Step 3: Place guards
        for (const auto& guard : guards) {
            grid[guard[0]][guard[1]] = 'G';
        }

        // Step 4: Simulate guard vision
        for (const auto& guard : guards) {
            int row = guard[0], col = guard[1];

            // Look Up
            for (int r = row - 1; r >= 0 && grid[r][col] != 'W' && grid[r][col] != 'G'; --r) {
                grid[r][col] = 'S';
            }

            // Look Down
            for (int r = row + 1; r < m && grid[r][col] != 'W' && grid[r][col] != 'G'; ++r) {
                grid[r][col] = 'S';
            }

            // Look Right
            for (int c = col + 1; c < n && grid[row][c] != 'W' && grid[row][c] != 'G'; ++c) {
                grid[row][c] = 'S';
            }

            // Look Left
            for (int c = col - 1; c >= 0 && grid[row][c] != 'W' && grid[row][c] != 'G'; --c) {
                grid[row][c] = 'S';
            }
        }

        // Step 5: Count unguarded cells
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '.') {
                    ++count;
                }
            }
        }

        return count;
    }
};
