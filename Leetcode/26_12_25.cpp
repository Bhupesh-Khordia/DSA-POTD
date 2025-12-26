class Solution {
public:
    int bestClosingTime(string cu) {

        int n = cu.size();

        int penalty = 0;
        for(char ch : cu){
            if(ch == 'Y') penalty++;
        }

        int minPenalty = penalty;
        int ans = 0;

        for(int i = 0; i < n; i++) {

            if(cu[i] == 'Y') penalty--;  
            else penalty++;              

            if(penalty < minPenalty){
                minPenalty = penalty;
                ans = i + 1;
            }
        }

        return ans;
    }
};
