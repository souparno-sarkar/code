class Solution 
{
public:
    int mahualPuraWavy(string s)
    {
        int cnt = 0;
        for(int i=1;i<s.size()-1;i++)
        {
            if(s[i-1] < s[i] && s[i] > s[i+1])
                cnt++;
            else if(s[i-1] > s[i] && s[i] < s[i+1])
                cnt++;
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) 
    {
        int res = 0;
        for(int i=num1;i<=num2;i++)
        {
            string s = to_string(i);
            int a = mahualPuraWavy(s);
            res += a;
        }
        return res;
    }
};