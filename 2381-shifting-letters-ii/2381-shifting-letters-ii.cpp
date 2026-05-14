class Solution 
{
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        // Diffrence array;
        vector<int> res(s.size() , 0);
        for(int i=0;i<shifts.size();i++)
        {
            int st = shifts[i][0];
            int end = shifts[i][1];

            if(shifts[i][2] == 0)
            {
                res[st] -= 1;
                if(end+1 < s.size())
                {
                    end++;
                    res[end] += 1;
                }
            }
            else
            {
                res[st] += 1;
                if(end+1 < s.size())
                {
                    end++;
                    res[end] -= 1;
                }
            }
        }

        for(int i=1;i<res.size();i++)
            res[i] += res[i-1];
        
        for(int i=0;i<s.size();i++)
        {
            int shift = res[i]%26;
            if(shift < 0)
                shift += 26;   // handel the negative int for alphabet oooohh  soup;
            int a = s[i]-'a';
            a = (a + shift)%26;
            s[i] = a + 'a';
        }
        return s;
    }
};