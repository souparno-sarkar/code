class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visit(n+1 , false);
        for(int i=0;i<n;i++)
        {
            if(nums[i] > 0 && nums[i] <= n)
                visit[nums[i]] = true;
        }
        for(int i=1;i<=n;i++)
        {
            if(visit[i] == false)
                return i;
        }
        return n+1;
    }
};