class Solution {
public:
    int ans = INT_MIN;
    int maximumEnergy(vector<int>& energy, int k) {
        // int n = energy.size();

        // int ans = INT_MIN;
        // for(int i=0; i<n; i++){
        //     rec(energy, k, n, i, 0, ans);
        // }
        // return ans;


        int n = energy.size();
        vector<int> dp(n , 0);
        for(int i = n-1; i>=0; i--){
                dp[i] = energy[i];  
                if(i+k <n){
                    dp[i] += dp[i+k];
                }
                ans = max(ans, dp[i]);
        }

        return ans;
    }
    void rec(vector<int>&energy, int k , int n, int ind , int currSum, int &ans){
            if(ind >=n){
                ans = max(ans, currSum);
                return;                
            }
            currSum += energy[ind];
            rec(energy, k ,n, ind+k,currSum, ans);
    }
};
