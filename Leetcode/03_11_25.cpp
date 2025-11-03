class Solution {
public:
    int minCost(string s, vector<int>&arr) {
        int n=arr.size();
        char prev='x';
        int previnx=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(prev==s[i]){
                ans+=min(arr[i],arr[previnx]);
                if(arr[i]>arr[previnx]){
                    previnx=i;
                }
            }
            else{
                prev=s[i];
                previnx=i;
            }
        }
        return ans;
    }
};
