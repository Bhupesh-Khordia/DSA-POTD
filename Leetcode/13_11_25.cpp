class Solution {
public:
    int maxOperations(string s) {
        int ones = 0;
        int moves = 0;
        int prev = 0;
        for(auto c : s)
        {
            if(c=='1')
            {
                ones++;
                prev = 1;
            }
            else if(prev == 1)
            {
                moves += ones;
                prev = 0;
            }

        }
        return moves;
    }
};
