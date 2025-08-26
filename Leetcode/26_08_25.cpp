class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int ansArea = 0;
        long long maxi = 0;
        for(auto &d : dimensions) {
            int length = d[0];
            int breadth = d[1];
            long long diagonalSq = 1LL * length * length + 1LL * breadth * breadth;
            if(diagonalSq > maxi) {
                ansArea = length * breadth;
                maxi = diagonalSq;
            } else if (diagonalSq == maxi) {
                ansArea = max(ansArea, length * breadth);
            }
        }
        return ansArea;
    }
};
