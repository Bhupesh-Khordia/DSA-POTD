class Solution {
public:
    int smallestNumber(int n) {
        // we find the lower bound for the n such that 2^x > n 
        int x = 1;
        while(x<=n){
            x = x*2;
        }
        return x-1;
    }
};
