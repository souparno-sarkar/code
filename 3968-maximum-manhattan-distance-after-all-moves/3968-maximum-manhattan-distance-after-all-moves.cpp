class Solution 
{
public:
    int maxDistance(string moves) 
    {
        int vertical = 0;
        int hori = 0;
        int idx = 0; 
        for(auto i : moves)
        {
            if(i=='U')
                vertical += 1;
            else if(i=='D')
                vertical -= 1;
            else if(i=='R')
                hori += 1;
            else if(i=='L')
                hori -= 1;
            else
                idx += 1;
        }    
        int res = abs(vertical) + abs(hori) + idx;
        return res;
    }
};