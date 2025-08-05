class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=fruits.size();
        for(int x: fruits){
            for(int& B: baskets){// B must be called by ref
                if (x<=B){
                    ans--;
                    B=0;
                    break;
                }
            }
        }
        return ans;
    }
};
