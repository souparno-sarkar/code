class Solution 
{
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) 
    {
        set<int> st1(nums1.begin() , nums1.end());
        set<int> st2(nums2.begin() , nums2.end());

        for(int i=0;i<nums2.size();i++)
        {
            if(st1.find(nums2[i]) != st1.end())
                st1.erase(nums2[i]);
        }    

        for(int i=0;i<nums1.size();i++)
        {
            if(st2.find(nums1[i]) != st2.end())
                st2.erase(nums1[i]);
        }

        vector<vector<int>> res;
        vector<int> vec1(st1.begin() , st1.end());
        vector<int> vec2(st2.begin() , st2.end());
        res.push_back(vec1);
        res.push_back(vec2);
        return res;
    }
};