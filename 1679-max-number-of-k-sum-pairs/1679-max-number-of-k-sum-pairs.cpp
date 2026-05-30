class Solution 
{
public:
    int maxOperations(vector<int>& nums, int k) 
    {
        int cnt = 0;
        sort(nums.begin() , nums.end());
        int left = 0;
        int right = nums.size()-1;
        while(left < right)
        {
            int sum = nums[left]+nums[right];
            if( sum == k)
            {
                cnt++;
                left++;
                right--;
            }
            else if(sum > k)
                right--;
            else
                left++;
        }   
        return cnt;
    }
};