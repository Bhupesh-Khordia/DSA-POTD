// https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/description/?envType=daily-question&envId=2025-06-29

class Solution {
public:
    int mod=1000000007;
    int numSubseq(vector<int>& nums, int target) 
    {
        sort(nums.begin(),nums.end());
        int res=0,n=nums.size(),i=0,j=n-1;
        vector<int>pow2(n+1,1);
        for(int i=1;i<=n;i++)
        {
            pow2[i]=(2*pow2[i-1])%mod;
        }
        while(i<=j)
        {
            if(nums[j]+nums[i]<=target)
            {
                res=(res+pow2[j-i])%mod;
                i++;
            }
            else
                j--;
        }
        return res;
    }
};
