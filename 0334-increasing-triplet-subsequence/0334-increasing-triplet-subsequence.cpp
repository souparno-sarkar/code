class Solution {
public:
    bool des_sort(vector<int>& arr , vector<int>& nums)
    {
        sort(arr.begin() , arr.end());
        reverse(arr.begin() , arr.end());
        return (arr == nums);
    }
    bool check(vector<int>& nums)
    {
        set<int> st(nums.begin() , nums.end());
        return (st.size() < 3);
    }
    bool increasingTriplet(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> arr = nums;
        if(check(nums))
            return false;
        if(des_sort(arr , nums))
            return false;
        else
        {
            for(int i=0;i<n;i++)
            {
                for(int j=i;j<n;j++)
                {
                    if(nums[i] < nums[j])
                    {
                        for(int k=j;k<n;k++)
                        {
                            if(nums[j] < nums[k])
                            {
                                return true;
                            }
                        }
                    }
                }
            }
        }
        return false;    
    }
};