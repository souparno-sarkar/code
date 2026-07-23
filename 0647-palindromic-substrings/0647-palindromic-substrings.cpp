class Solution 
{
public:
    bool isPal(string s)
    {
        string temp = s;
        reverse(temp.begin() , temp.end());
        return (s == temp);
    }
    int countSubstrings(string s) 
    {
        int n = s.size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                string temp = s.substr(i , j-i+1);
                if(isPal(temp))
                    cnt++;
            }
        }  
        return cnt;  
    }
};