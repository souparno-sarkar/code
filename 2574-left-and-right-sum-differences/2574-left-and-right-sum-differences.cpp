class Solution 
{
public:
    vector<int> leftRightDifference(vector<int>& nums) 
    {
        int n = nums.size();
        int sum = 0;
        int prevSum = 0;
        for(int i : nums)
            sum += i;
        for(int i=0;i<n;i++)
        {
            if(i == 0)
            {
                prevSum = nums[0];
                nums[0] = sum-prevSum;
            }
            else if(i == n-1)
            {
                int a = nums[n-1];
                nums[n-1] = sum-a;
            }
            else
            {
                int lSum = prevSum;
                prevSum += nums[i];
                int rSum = sum - prevSum;
                nums[i] = abs(lSum-rSum); 
            }
        }
        return nums;     
    }
};