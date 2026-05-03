class Solution 
{
public:
    bool rotateString(string s, string goal) 
    {
        if(s.size() != goal.size()) return false;

        string temp = s+s;
        int flag = temp.find(goal);
        return flag == -1 ? false : true;    
    }
};