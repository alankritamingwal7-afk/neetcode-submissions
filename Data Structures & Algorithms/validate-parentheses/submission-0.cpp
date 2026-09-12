class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int i=0;
        int n=s.size();
        if(n==1){
            return false;
        }
        for(i=0;i<n;i++){
            if(s[i]=='[' ||s[i]=='{'||s[i]=='('){
                st.push(s[i]);
            }
            else{
                if(st.size()==0){
                    return false;
                }
                char top = st.top();
                st.pop();
                if(s[i]==')' && top!='('||s[i]=='}' && top!='{'||s[i]==']' && top!='['){
                    return false;
                }
            }

        }
        return st.empty();
    }
};
