class Solution 
{
public:
    int numSpecial(vector<vector<int>>& nums) 
    {
        int count = 0;
        int n = nums.size();
        int m = nums[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int row = 0 , col = 0;
                if(nums[i][j] == 1)
                {
                    for(int k=0;k<n;k++)
                    {
                        if(nums[k][j] == 1)
                            col++;
                    }
                    for(int k=0;k<m;k++)
                    {
                        if(nums[i][k] == 1)
                            row++;
                    }
                    if(row == 1 && col == 1)
                        count++;
                }
            }
        } 
        return count;
    }
};