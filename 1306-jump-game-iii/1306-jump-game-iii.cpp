class Solution 
{
public:
    bool dfs(vector<int>& arr , int i)
    {
        if(i >= arr.size() || i < 0 || arr[i] < 0)
            return false;
        if(arr[i] == 0)
            return true;
        arr[i] *= -1;
        int a = dfs(arr , i-arr[i]);
        int b = dfs(arr , i+arr[i]);
        return a || b;
    }
    bool bfs(vector<int>& arr , int i)
    {
        queue<int> q;
        vector<bool> visited(arr.size() , false);
        q.push(i);
        visited[i] = true;

        while(!q.empty())
        {
            int idx = q.front();
            q.pop();

            if(arr[idx] == 0)
                return true;

            int left = idx-arr[idx];
            int right = idx+arr[idx];

            if(left >= 0 && !visited[left])
            {
                q.push(left);
                visited[left] = true;
            }
            if(right < arr.size() && !visited[right])
            {
                q.push(right);
                visited[right] = true;
            }
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) 
    {
        return bfs(arr , start) && dfs(arr , start);
    }
};