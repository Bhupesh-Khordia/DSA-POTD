class Solution {
public:
    bool hasSameDigits(string s) {
        
        while(s.length()>2){
            string s2="";
            for(int i=0;i<s.length()-1;i++){
                int num=(s[i]-'0'+s[i+1]-'0')%10;
                s2=s2+to_string(num);
            }
            s=s2;
        }
        if(s[0]==s[1]){
            return true;
        }else{
            return false;
        }
    }
};
