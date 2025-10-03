class Solution {
public:
    int trapRainWater(vector<vector<int> >& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        if (m < 3 || n < 3) return 0;

        vector<vector<bool> > visited(m, vector<bool>(n, false));
        // Min-heap: {height, {x, y}}
        priority_queue<pair<int, pair<int, int> >,
                       vector<pair<int, pair<int, int> > >,
                       greater<pair<int, pair<int, int> > > > pq;

        // Push all border cells into the heap
        for (int i = 0; i < m; ++i) {
            pq.push(make_pair(heightMap[i][0], make_pair(i, 0)));
            pq.push(make_pair(heightMap[i][n - 1], make_pair(i, n - 1)));
            visited[i][0] = true;
            visited[i][n - 1] = true;
        }

        for (int j = 1; j < n - 1; ++j) {
            pq.push(make_pair(heightMap[0][j], make_pair(0, j)));
            pq.push(make_pair(heightMap[m - 1][j], make_pair(m - 1, j)));
            visited[0][j] = true;
            visited[m - 1][j] = true;
        }

        int ans = 0;
        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        while (!pq.empty()) {
            pair<int, pair<int, int> > cell = pq.top();
            pq.pop();

            int h = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;

            for (int k = 0; k < 4; ++k) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    int nh = heightMap[nx][ny];
                    if (h > nh) ans += h - nh;
                    pq.push(make_pair(max(h, nh), make_pair(nx, ny)));
                }
            }
        }

        return ans;
    }
};
