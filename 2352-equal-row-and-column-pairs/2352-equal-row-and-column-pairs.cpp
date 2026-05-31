class Solution 
{
public:
    int equalPairs(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        int cnt = 0;

        map<vector<int>, int> mp;

        for(int i = 0; i < n; i++)
            mp[grid[i]]++;

        for(int i = 0; i < n; i++)
        {
            vector<int> arr;

            for(int j = 0; j < n; j++)
                arr.push_back(grid[j][i]);

            cnt += mp[arr];
        }

        return cnt;
    }
};