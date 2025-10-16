class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> mpp;
        for(auto i:nums){
            int k=i%value;
            if(k<0) k=value+k;
            mpp[k]++;
        }
        int cnt=0;
        while(cnt<INT_MAX){
            if(!mpp[cnt%value]){
                return cnt;
            }
            else
                mpp[cnt%value]--;
            cnt++;
        }
        return cnt;
    }
};
