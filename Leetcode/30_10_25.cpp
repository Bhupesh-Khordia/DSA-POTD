class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();

        int prev = 0;
        int curr = 0;

        int ans = 0;

        for(int i = 0; i < n; i++) {
            curr = target[i];

            if(curr > prev) { //Condition
                ans += curr - prev;
            }

            prev = curr; //Update
        }

        return ans;
    }
};
