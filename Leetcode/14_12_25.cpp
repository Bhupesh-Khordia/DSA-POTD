class Solution {
public:
const int MOD = 1e9+7;
    int numberOfWays(string corridor) {

        int NumberOfSeats = 0;

        for(int i=0; i<corridor.size(); i++){
            if(corridor[i]=='S') NumberOfSeats++;
        }
        if(NumberOfSeats%2==1 or NumberOfSeats==0) return 0;//not possible any division

        if(NumberOfSeats==2) return 1;

        int countS=0;
        long long int ans=1;
        int curCount=0;
        for(int i=0; i<corridor.size(); i++){

            if(corridor[i]=='S'){
                countS++;
            }

            if(countS==2){
                curCount++;
            }
            if(countS==3){
                ans*=curCount;
                ans%=MOD;
                curCount=0;
                countS=1;
            }

        }

        return ans;
    }
};
