class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string>ans;
        unordered_map<string,int>map;
        int i=0;
        for(string s : words){
            string a=s;
            sort(s.begin(),s.end());
            if(!map.count(s)){
                map[s]=i;
                ans.push_back(a);
            }
            if(map.count(s) and i-map[s]>1)
                ans.push_back(a);
                map[s]=i;
            i++;
        }
        return ans;
    }
};
