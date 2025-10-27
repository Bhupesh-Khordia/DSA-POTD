class Solution {
public:
    int count(string s){
        int freq = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]=='1') freq++;
        }
        return freq;
    }
    int numberOfBeams(vector<string>& bank) {
        int MC = 0; // MAIN COUNT(MC)
        int curr = 0;
        int prev = 0;
        
        int i = 0;
        while(i < bank.size() && (prev = count(bank[i])) == 0) i++;

        for(i = i + 1; i < bank.size(); i++){
            curr = count(bank[i]);
            if(curr != 0){
                MC += prev * curr;
                prev = curr;
            }
        }
        return MC;
    }
};
