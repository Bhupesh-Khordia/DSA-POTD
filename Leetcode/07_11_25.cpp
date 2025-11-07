class Solution {
public:
    bool check(long long p,vector<int>&v,int r,int k )
    {
        int n = v.size();
        long long wndSum = 0;
        for(int i=0;i<r;i++) wndSum +=v[i];
        vector<long long>added(v.size(),0);
        for(int i=0;i<n;i++){
            if(i+r<n) wndSum += v[i+r] ;
            if(i-r-1>=0) wndSum -= (v[i-r-1] + added[i-r-1]);
            if(wndSum < p){
                long long req = p - wndSum;
                if(req>k) return false;
                k -= req;
                added[min(i+r,n-1)] = req;
                wndSum += req;
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        long long l = 0;
        long long h = 1e18;
        long long ans = 0;

        while(l<=h){
            long long mid = (l+h)/2;
            if(check(mid,stations,r,k)){
                l = mid+1;
                ans = mid;
            }
            else h = mid-1;
        }
        return ans;
    }
};
