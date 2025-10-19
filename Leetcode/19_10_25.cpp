class Solution {
public:
    void add(string& s,int a){
        for(int i=1;i<s.length();i+=2){
            s[i]=((s[i]-'0'+a)%10)+'0';
        }
    }

    void rotate(string& s,int b){
        //rotation by b places to right
        reverse(begin(s),end(s));
        reverse(begin(s),begin(s)+b);
        reverse(begin(s)+b,end(s));
    }



    string findLexSmallestString(string s, int a, int b) {
        string smallestStr=s;

        queue<string> q;
        unordered_set<string> vis;
        q.push(s);
        vis.insert(s);

        while(!q.empty()){
            string curr=q.front();
            q.pop();

            if(smallestStr > curr){
                smallestStr=curr;
            }

            string temp1=curr;
            //add
            add(temp1,a);
            if(!vis.count(temp1)){
                q.push(temp1);
                vis.insert(temp1);
            }

            string temp2=curr;
            //rotate
            rotate(temp2,b);
            if(!vis.count(temp2)){
                q.push(temp2);
                vis.insert(temp2);
            }
        }
        return smallestStr;
    }
};
