class Solution {    
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;

        int i = 0;
        int j = 0;

        int n = prices.size();

        while(j<n){
            if(j>0 && prices[j]-prices[j-1]!=-1){
                i=j;
            }
            ans += (j-i+1);
            j++;

        }

        return ans;
    }
};
