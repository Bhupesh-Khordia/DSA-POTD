class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int x = n - 1;
        int y = 0;
        while(!(x == 0 && y == n - 1)) {
            bool decreasing = false;
            if(y == 0) {
                // decreasing
                decreasing = true;
            }

            int newx = x;
            int newy = y;
            
            vector<int> temp;
            while( newx >= 0 && newx < n && newy >= 0 && newy < n) {
                temp.push_back(grid[newx][newy]);
                newx++;
                newy++;
            }

            decreasing ? sort(temp.begin(), temp.end(), greater<int> ()) : sort(temp.begin(), temp.end());

            int idx = 0;
            newx = x;
            newy = y;
            while( newx >= 0 && newx < n && newy >= 0 && newy < n && idx < temp.size()) {
                grid[newx][newy] = temp[idx++];
                newx++;
                newy++;
            }

            // Change diagonal
            if(x == 0) y++;
            else x--;
        }
        return grid;
    }
};
