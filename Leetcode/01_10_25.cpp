class Solution {
public:
    int numWaterBottles(int num, int n) {
        int ans=num;
        while(num>=n){
            int c=num/n;
          ans+=c;
          num=c+(num%n);
        }
        return ans;
    }
};
