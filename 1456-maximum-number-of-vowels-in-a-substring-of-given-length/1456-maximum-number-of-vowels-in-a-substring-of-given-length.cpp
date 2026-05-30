class Solution {
public:
    bool isVowel(char a)
    {
        if(a=='a' || a=='e' || a=='i' || a=='o' || a=='u')
            return true;
        return false;
    }
    int maxVowels(string s, int k) 
    {
        int st=0;
        int e=0;
        int cnt = 0 , max_cnt = 0;
        while(e < s.size())
        {
           if(isVowel(s[e]))
            cnt++;
            if(e-st+1 > k)
            {
                if(isVowel(s[st]))
                    cnt--;
                st++;
            }
            if(e-st+1 == k)
                max_cnt = max(max_cnt , cnt);
            e++;
        } 
        return max_cnt;
    }
};