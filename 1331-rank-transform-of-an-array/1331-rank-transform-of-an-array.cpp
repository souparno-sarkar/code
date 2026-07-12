class Solution 
{
public:
    vector<int> arrayRankTransform(vector<int>& arr) 
    {
        int n = arr.size();
        vector<int> nums = arr;
        sort(nums.begin() , nums.end());
        unordered_map<int,int> mp;
        int rank = 1;
        for(auto i : nums)
        {
            if(!mp.count(i))
                mp[i] = rank++;
        }
        for(auto& i : arr)
            i = mp[i];
        return arr;
    }
};