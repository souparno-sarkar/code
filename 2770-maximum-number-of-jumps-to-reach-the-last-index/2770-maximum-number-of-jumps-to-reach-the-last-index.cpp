class Solution 
{
public:
    int maximumJumps(vector<int>& nums, int target) 
    {
        int n = nums.size();
        vector<int> t(n , -1);
        t[0] = 0;
        for(int i=0;i<n;i++)
        {
            if(t[i] == -1) continue;
            for(int j=i+1;j<n;j++)
            {
                int diff = abs(nums[j]-nums[i]);
                if(diff <= target)
                {
                    t[j] = max(t[i]+1 , t[j]); 
                }
            }
        }  
        if(t[n-1] == 0) return -1;  
        return t[n-1];
    }
};