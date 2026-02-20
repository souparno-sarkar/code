class Solution 
{
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        vector<int> arr;
        unordered_map<int,int>freq;
        int n = nums.size()/3;
        for(int a : nums)
            freq[a]++;
        for(auto i : freq)
        {
            if(i.second > n)
                arr.push_back(i.first);
        }
        return arr;    
    }
};