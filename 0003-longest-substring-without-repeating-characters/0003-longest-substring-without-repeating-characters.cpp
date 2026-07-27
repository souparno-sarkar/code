class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int> mp;
        int max_seq = 0;
        int n = s.size();
        int l = 0;
        int r = 0;
        while(r < n)
        {
            mp[s[r]]++;
            if(mp.size() == r-l+1)
                max_seq = max(max_seq , r-l+1);
            else if(mp.size() < r-l+1)
            {
                mp[s[l]]--;
                if(mp[s[l]] == 0)
                    mp.erase(s[l]);
                l++;
            }
            r++;
        }
        return max_seq;
    }
};