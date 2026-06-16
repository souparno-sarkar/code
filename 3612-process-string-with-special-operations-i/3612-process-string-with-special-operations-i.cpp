class Solution {
public:
    string hashFound(string res)
    {
        res += res;
        return res;
    }
    string perFound(string res)
    {
        reverse(res.begin() , res.end());
        return res;
    }
    string starFound(string res)
    {
        if(res.empty())
            return "";
        res.pop_back();
        return res;
    }
    string processStr(string s) 
    {
        string res = "";
        for(auto i : s)
        {
            if(isalpha(i) && islower(i))
                res += i;
            else if(i == '#')
                res = hashFound(res);
            else if(i == '%')
                res = perFound(res);
            else if(i == '*')
                res = starFound(res);
            else
                continue;
        }    
        return res;
    }
};