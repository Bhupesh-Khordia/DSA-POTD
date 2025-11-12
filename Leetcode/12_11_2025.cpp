class Solution {
public:
    //TC = O(n^2 * log(max(a, b)))    &&    SC = O(1)
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        int count1 = 0;

        for(int &num: nums) { //1 Element Atleast One
            if(num == 1) {
                count1++;
            }
        }

        if(count1 > 0) {
            return n - count1;
        }

        //No one GCD Found
        int operations = INT_MAX;

        for(int i = 0; i < n-1; i++) {
            int GCD = nums[i];
            for(int j = i+1; j < n; j++) {
                GCD = gcd(GCD, nums[j]);

                if(GCD == 1 ){ //only1
                    operations = min(operations, j-i);
                }
            }
        }

        return operations != INT_MAX ? (n-1) + operations : -1; //Edge CASE BHI CHECK
    }
};
