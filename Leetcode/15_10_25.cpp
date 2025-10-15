class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
       map<int,int>mp;
       int start=0;
       for(int i=1;i<nums.size();i++){
        if(nums[i]<=nums[i-1]){
            mp.insert({start,i-1});
            start=i;
        }
       }
       mp.insert({start,nums.size()-1});
       int a=INT_MIN;
       vector<int>v;
       for(auto &it :mp){
            a=max(a,(it.second-it.first+1)/2);
            v.push_back(it.second-it.first+1);
       } 
       int prev=v[0];
       int ans=INT_MIN;
       for(int i=1;i<v.size();i++){
       int f=min(prev,v[i]);
       ans=max(f,ans);

        prev=v[i];
       }
       return max(ans,a);
    }
};
