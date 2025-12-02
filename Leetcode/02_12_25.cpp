class Solution {
public:
long long nc2(long long n)
{
    if(n<2)
    return 0;
    return n*(n-1)/2;
}
    int countTrapezoids(vector<vector<int>>& points) {

        unordered_map<int,int>m;

        for(auto p:points) // calculate number of coordinates at each horizontal level y
        {
        m[p[1]]++;
        }

        vector<long long> levelPairs; // store nC2 for each level in a vector
        for(auto p : m)
        levelPairs.push_back(nc2(p.second));
        
        long long sum=0; //calculate sum of nC2 of all levels
        for(auto x:levelPairs)
        sum+=x*1LL;

        long long ans=0;
        for(int i=0;i<levelPairs.size();i++)
        {
            sum-=levelPairs[i];
            ans=(ans+sum*levelPairs[i])%1000000007;
        }
        return ans;

        
    }
};
