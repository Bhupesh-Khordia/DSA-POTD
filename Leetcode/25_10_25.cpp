class Solution {
public:
    int totalMoney(int n) {
        int z = n/7;
        int x = n% 7;

        int total   = 0;
        total = 28*z + 7*(z*(z-1)/2);

        int remains = 0;
        for(int i=1;i<=x;++i)
        {
            remains += z + i;
        }

        return total + remains;
    }
};
