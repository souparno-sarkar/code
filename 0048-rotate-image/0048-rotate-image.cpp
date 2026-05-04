class Solution 
{
public:
    void rotate(vector<vector<int>>& arr) 
    {
        int n = arr.size();
        vector<vector<int>>t_arr(n,vector<int>(n));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                t_arr[j][i] = arr[i][j]; 
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++)
            {
                swap(t_arr[i][j] , t_arr[i][n-j-1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                arr[i][j] = t_arr[i][j];
            }
        }
    }
};