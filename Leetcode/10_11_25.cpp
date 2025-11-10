class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> s; int ans = 0;
        for(int &i : nums){
            if(i == 0){
                ans += s.size(); s = stack<int>();
                continue;
            }
            while(!s.empty() && s.top() > i){
                ans ++; s.pop();
            }
            if(s.empty() || s.top() != i) s.push(i);  
        }
        ans += s.size();
        return ans;
    }
};
