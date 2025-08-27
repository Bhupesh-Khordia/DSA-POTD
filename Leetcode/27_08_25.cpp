class Solution {
public:

    int m,n;
    int dp[500][500][2][4];
    int dfs(vector<vector<int>>& grid,int row,int col,bool canchange,int dir)
    {
        if(row<0||col<0||row==m||col==n||grid[row][col]==1) return 0;
        if(dp[row][col][canchange][dir]!=-1) return dp[row][col][canchange][dir];
        int ans1=-10000,ans2=-10000;
        if(dir==0)
        {
            int previous=grid[row+1][col+1];
            if(previous!=1&&previous==grid[row][col]) return 0;
            ans1=dfs(grid,row-1,col-1,canchange,dir);
            if(canchange) ans2=dfs(grid,row-1,col+1,0,1);
        }
        else if(dir==1)
        {
            int previous=grid[row+1][col-1];
            if(previous!=1&&previous==grid[row][col]) return 0;
            ans1=dfs(grid,row-1,col+1,canchange,dir);
            if(canchange) ans2=dfs(grid,row+1,col+1,0,2);
        }
        else if(dir==2)
        {
            int previous=grid[row-1][col-1];
            if(previous!=1&&previous==grid[row][col]) return 0;
            ans1=dfs(grid,row+1,col+1,canchange,dir);
            if(canchange) ans2=dfs(grid,row+1,col-1,0,3);
        }
        else
        {
            int previous=grid[row-1][col+1];
            if(previous!=1&&previous==grid[row][col]) return 0;
            ans1=dfs(grid,row+1,col-1,canchange,dir);
            if(canchange) ans2=dfs(grid,row-1,col-1,0,0);
        }
        return dp[row][col][canchange][dir]=1+max(ans1,ans2);
    }

    int lenOfVDiagonal(vector<vector<int>>& grid) 
    {
        m=grid.size();
        n=grid[0].size();
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    ans=max(ans,1);
                    if(i-1>=0&&j-1>=0&&grid[i-1][j-1]==2) ans=max(ans,1+dfs(grid,i-1,j-1,1,0));
                    if(i-1>=0&&j+1<n&&grid[i-1][j+1]==2) ans=max(ans,1+dfs(grid,i-1,j+1,1,1));
                    if(i+1<m&&j+1<n&&grid[i+1][j+1]==2) ans=max(ans,1+dfs(grid,i+1,j+1,1,2));
                    if(i+1<m&&j-1>=0&&grid[i+1][j-1]==2) ans=max(ans,1+dfs(grid,i+1,j-1,1,3));
                }
            }
        }
        return ans;
    }
};



