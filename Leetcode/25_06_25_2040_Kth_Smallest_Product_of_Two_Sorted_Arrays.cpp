// https://leetcode.com/problems/kth-smallest-product-of-two-sorted-arrays/description/?envType=daily-question&envId=2025-06-25

class Solution {
public:
    using ll = long long;
    bool isPossible(ll x, vector<int>& nums1, vector<int>& nums2, ll k){
        int n1 = nums1.size();
        int n2 = nums2.size();
        ll count=0;
        for(int i=0;i<n1;i++){
            if(nums1[i]<0){
                ll rem = ceil((double)x/nums1[i]);
                int ind = lower_bound(nums2.begin(), nums2.end(), rem)-nums2.begin();
                count += (n2-ind);
            }else if(nums1[i]>0){
                ll rem = floor((double)x/nums1[i]);
                int ind = upper_bound(nums2.begin(), nums2.end(), rem)-nums2.begin();
                count += ind;
            }else{
                if(x>=0){
                    count += n2;
                }
            }
            if(count>=k) return true;
        }
        return count>=k;
    }
    ll kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, ll k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        ll low = -1e10;
        ll high = 1e10;
        ll ans=0;
        while(low<=high){
            ll mid = low+(high-low)/2;
            if(isPossible(mid, nums1, nums2, k)){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
