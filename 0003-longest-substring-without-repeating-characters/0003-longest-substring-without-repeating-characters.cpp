/*Notes : Take a hash table and then insert the element as per given string 
        Check wheteher the alphabets are repeting or not
        if repeting then check that the index of the repeated alphabet is >= left then update 
        left = index+1;
*/

#include<bits/stdc++.h>
#define vi vector<int>
#define um_i unordered_map<int , int>
#define um_c unordered_map<char , int>
#define co cout <<
#define ci cin >>
using ll = long long;
using namespace std;

class Solution 
{
public:
    int lengthOfLongestSubstring(string s) 
    {
        if(s.size() == 0 || s.size() == 1)
            return s.size();

        um_c mp;

        int str = 0 , end = 0;
        int max_size = 0;

        while(end < s.size())
        {
            if(mp.find(s[end]) == mp.end())
            {
                mp[s[end]]++;
                end++;
            }
            else
            {
                max_size = max(max_size , (int)mp.size());
                mp.clear();
                str++;
                end = str;
            }
        }

        max_size = max(max_size , (int)mp.size());

        return max_size;
    }
};