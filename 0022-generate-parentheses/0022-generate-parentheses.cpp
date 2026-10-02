class Solution {
public:
    void solve(vector<string>& nums , int op , int cl , string open)
    {
        if(op==0 && cl==0)
        {
            nums.push_back(open);
            return;
        }
        if(op != 0)
        {
            string op1 = open;
            op1.push_back('(');
            solve(nums,op-1,cl,op1);
        }
        if(op < cl)
        {
            string op2 = open;
            op2.push_back(')');
            solve(nums,op,cl-1,op2);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> nums;
        solve(nums,n,n,"");
        return nums;
    }
};