class Solution {
public:
    long long flowerGame(int n, int m) {
        if(n & 1) {
            return 1LL*(((n/2)*((m/2)+(m%2))) + (((n/2)+(n%2))*(m/2)) );
        }
        return 1LL*(n/2)*((m/2)+((m/2)+(m%2)));
    }
};
