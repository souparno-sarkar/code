using ll = long long;
class Solution 
{
public:
    long long maxTotalValue(vector<int>& nums, int k) 
    {
        ll max_num = *max_element(nums.begin() , nums.end());
        ll min_num = *min_element(nums.begin() , nums.end());
        ll res = max_num - min_num;
        return (ll)res*k;
    }
};