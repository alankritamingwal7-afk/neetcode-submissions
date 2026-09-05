class Solution {
public:
    void solve(int close,int open,string op,vector<string>& ans){
        if(open==0 && close==0){
            ans.push_back(op);
            return;
        }
        if(open==close){
            string op1=op;
            op1.push_back('(');
            solve(close,open-1,op1,ans);
        }
        else if(open==0){
            string op1=op;
            op1.push_back(')');
            solve(close-1,open,op1,ans);
        }
        else if(close==0){
            string op1=op;
            op1.push_back('(');
            solve(close,open-1,op1,ans);
        }
        else{
            string op1=op;
            string op2=op;
            op1.push_back('(');
            op2.push_back(')');
            solve(close,open-1,op1,ans);
            solve(close-1,open,op2,ans);
        }
    }


    vector<string> generateParenthesis(int n) {
        int close=n;
        int open=n;
        vector<string> ans;
        string op="";
        solve(close,open,op,ans);
        return ans;       
    }
};
