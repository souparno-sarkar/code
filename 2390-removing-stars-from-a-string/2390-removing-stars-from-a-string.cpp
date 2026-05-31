// beta stack use kar le ;
class Solution 
{
public:
    string removeStars(string s) 
    {
        stack<char> st;
        for(char i : s)
        {
            if(i == '*')
            {
                st.pop();
            }
            else
            {
                st.push(i);
            }
        }   
        s.erase(s.begin() , s.end()); 
        while(!st.empty())
        {
            s.push_back(st.top());
            st.pop();
        }
        reverse(s.begin() , s.end());
        return s;
    }
};