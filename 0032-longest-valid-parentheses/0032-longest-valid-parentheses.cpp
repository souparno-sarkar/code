// stack se 
/*int solWithStack(string s)
{
    stack<int>st;
    st.push(-1);
    int res = 0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
            st.push(i);
        else
        {
            st.pop();
            if(st.empty())
                st.push(i);
            else
                res = max(res , i-st.top());
        }
        return res;
    }
}*/
class Solution 
{
public:
    int longestValidParentheses(string s) 
    {
        int n = s.size();
        int stBracketCnt = 0;   
        int endBracketCnt = 0; 
        int res = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '(') stBracketCnt++;
            else endBracketCnt++;
            if(endBracketCnt == stBracketCnt)
                res = max(res , 2*endBracketCnt);
            else if(stBracketCnt < endBracketCnt)
            {
                endBracketCnt = 0;
                stBracketCnt = 0;
            }
        }
        endBracketCnt = 0;
        stBracketCnt = 0;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] == '(') stBracketCnt++;
            else endBracketCnt++;
            if(endBracketCnt == stBracketCnt)
                res = max(res , 2*endBracketCnt);
            else if(stBracketCnt > endBracketCnt)
            {
                endBracketCnt = 0;
                stBracketCnt = 0;
            }
        }
        return res;
    }
};  