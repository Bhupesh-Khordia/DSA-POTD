class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int mod=1e9+7;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k,0)));
        dp[0][0][grid[0][0]%k]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0&&j==0) continue;
                int num=grid[i][j];
                vector<int>empty(k,0);
                if(i-1>=0){
                    for(int l=0;l<k;l++){
                       if(dp[i-1][j][l]==0)
                            continue;
                        empty[(l+num)%k]=(empty[(l+num)%k]+dp[i-1][j][l])%mod;
                    }
                }
                if(j-1>=0){
                    for(int l=0;l<k;l++){
                       if(dp[i][j-1][l]==0)
                            continue;
                        empty[(l+num)%k]=(empty[(l+num)%k]+dp[i][j-1][l])%mod;
                    }
                }
                dp[i][j]=empty;
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<'('<<i<<','<<j<<')'<<endl;;
        //         for(int l=0;l<k;l++){
        //             cout<<dp[i][j][l]<<' ';
        //         }
        //         cout<<endl;
        //     }
        // }
        return dp[n-1][m-1][0];
    }
};
