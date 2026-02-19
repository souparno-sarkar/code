class Solution 
{
public:
    bool is_balance(vector<int> &nums)
    {
        int temp = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 0) continue;
            if(temp == 0)
                temp = nums[i];
            else if(nums[i] != temp)
                return false;
        }
        return true;
    }
    int longestBalanced(string s) 
    {
        int temp = INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            vector<int> nums(26,0);
            for(int j=i;j<s.size();j++)
            {
                nums[s[j]-'a']++;
                if(is_balance(nums))
                {
                    temp = max(temp , j-i+1);
                }
            }
        }
        return temp;    
    }
};