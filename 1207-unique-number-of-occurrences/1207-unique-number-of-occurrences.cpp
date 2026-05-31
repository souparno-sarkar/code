class Solution 
{
public:
    bool uniqueOccurrences(vector<int>& arr) 
    {
        unordered_map<int,int> mp;
        for(int i : arr)
            mp[i]++;

        vector<int> nums;
        for(auto& i:mp)
            nums.push_back(i.second);

        set<int> st;
        for(int i=0;i<nums.size();i++)
        {
            if(st.find(nums[i]) != st.end())
                return false;
            else
                st.insert(nums[i]);
        }  
        return true;
    }
};