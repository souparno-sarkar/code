using ll = long long;
class Solution 
{
public:
    long long maxSum(vector<int>& nums, int k, int mul) 
    {
        sort(nums.rbegin() , nums.rend());
        ll res = 0;
        int idx = 0;
        while(k--)
        {
            if(mul > 0)
                res += (ll)nums[idx]*mul;
            else
                res += nums[idx];
            mul--;
            idx++;
        }
        return res;
    }
};