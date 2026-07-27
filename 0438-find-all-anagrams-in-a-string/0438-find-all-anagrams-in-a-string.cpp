class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pfreq(26 , 0);
        vector<int> sfreq(26 , 0);
        vector<int> res;
        for(auto i : p)
            pfreq[i-'a']++;
        int k = p.size();
        for(int i=0;i<s.size();i++)
        {
            sfreq[s[i]-'a']++;
            if(i >= k)
                sfreq[s[i-k]-'a']--;
            if(pfreq == sfreq)
                res.push_back(i-k+1);
        } 
        return res;
    }
};