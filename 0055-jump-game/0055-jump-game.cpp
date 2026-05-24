class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        int n = nums.size();
        vector<bool> arr(n,false);
        arr[n-1] = true;
        for(int i=n-2;i>=0;i--)
        {
           int farthest = min(n-1 , i+nums[i]);
           {
            for(int j=0;j<=farthest;j++)
            {
                if(arr[j] == true)
                {
                    arr[i] = true;
                    break;
                }
            }
           } 
        }
        return arr[0];   
    }
};