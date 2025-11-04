class Solution {
public:
int xsum(int start,int end,vector<int>& nums,int count){
    int sum =0;

 unordered_map<int,int>mp;

    for(int i=start;i<=end;i++){
      mp[nums[i]]++;
    }

if(mp.size()<count){
    int total = 0;
    for(int i=start;i<=end;i++){
        total = total + nums[i];
    }
    return total;
}
    priority_queue<pair<int,int>>q;
    for(auto it : mp){
        q.push({it.second,it.first});
    }

    while(count--){
       int temp =  q.top().first*q.top().second;
       q.pop();
        sum = sum + temp;
    }

    return sum;
}
    vector<int> findXSum(vector<int>& nums, int k, int x) {

        int n = nums.size();
        vector<int>answer(n-k+1);

      for(int i=0;i<answer.size();i++){
        answer[i]=xsum(i,i+k-1,nums,x);
      }

      return answer; 
    }
};
