class Solution 
{
public:
    int maxDepth(string s) 
    {
        int count = 0;
        int max_cnt = 0;
        for(auto i : s)
        {
            if(i == '(')
                count++;
            else if(i == ')')
                count--;
            max_cnt = max(max_cnt , count);
        } 
        return max_cnt;   
    }
};