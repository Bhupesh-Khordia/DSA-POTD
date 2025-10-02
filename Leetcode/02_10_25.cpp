class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        while(numExchange <= numBottles) {
            ans++;
            numBottles -= numExchange; // Get full bottle
            numBottles++; //Drink 
            numExchange++;
        }
        return ans;
    }
};
