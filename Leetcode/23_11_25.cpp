class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int mod0 = 0;
        int mod1 = 0;
        int mod2 = 0;

        auto update = [&](int s) {
            switch(s % 3) {
                case 0: mod0 = max(mod0, s); break;
                case 1: mod1 = max(mod1, s); break;
                case 2: mod2 = max(mod2, s); break;
            }
        };
        
        for(int num : nums) {
            int sum0 = mod0 + num;
            int sum1 = mod1 + num;
            int sum2 = mod2 + num;

            update(sum0);
            update(sum1);
            update(sum2);
        }

        return mod0;
    }
};
