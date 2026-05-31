class Solution 
{
public:
    bool closeStrings(string word1, string word2) 
    {
        if(word1.size() != word2.size())
            return false;
        unordered_map<int,int> mp;
        for(auto i : word1)
            mp[i]++;
        int idx = 0;
        for(auto& i : mp)
        {
            if(mp.find(word2[idx++]) == mp.end())
                return false;
        }
        unordered_map<int,int> mp2;
        for(auto i : word2)
            mp2[i]++;
        
        vector<int> arr;
        vector<int> arr2;
        for(auto i : mp)
            arr.push_back(i.second);
        for(auto i : mp2)
            arr2.push_back(i.second);
        
        sort(arr.begin() , arr.end());
        sort(arr2.begin() , arr2.end());

        return (arr == arr2);
    }
};