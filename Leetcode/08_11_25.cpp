class Solution {
public:
    int minimumOneBitOperations(int n) {
        int ans = 0;
        int sign = 1;
        for(int  i =31;i>=0;i--){
            if(n & (1<<i)){
                int x = pow(2,i);
                ans += sign*(x+x-1);
                sign *= -1;
            }
        }
        return ans;
    }
};
