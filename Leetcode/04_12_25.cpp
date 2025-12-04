class Solution {
public:
    int countCollisions(string directions) {
        int n=directions.size();
        int collisions=0;
        
        stack<char>st;
        st.push(directions[0]);
        for(int i=1;i<n;i++){
            if(st.top()=='R' && directions[i]=='L'){
                collisions+=2;
                st.pop();
                st.push('S');
                st.push('S');
            }
            else if(st.top()=='S' && directions[i]=='L'){
                collisions+=1;
                st.push('S');
            }
            else if(st.top()=='R' && directions[i]=='S'){
                collisions+=1;
                st.pop();
                st.push('S');
                st.push('S');
                
            }
            else{
                st.push(directions[i]);
            }
        }
        int count=0;
        
        while(!st.empty() && st.top()=='R'){
            st.pop();
        }
        while(!st.empty()){
            if(st.top()=='R'){
                count+=1;
                
            }
            
                
            
            st.pop();
        }
        return collisions+count;
    }
};
