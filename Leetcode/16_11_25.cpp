class Solution {
public:
    int numSub(string s) {
        int n = s.length();
        int count = 0;
        int result = 0;
        const int mod = 1e9+7;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                count++;
                result = (result + count)%mod;
            }else{
                count = 0;
            }
        }
        return result;
    }
};
