class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int n = cost.size();
        int i = n-1-2;
        int sum=0;
        int sub=0;
        for(;i>=0;i-=3)
            sub += cost[i];
        for(int i=0;i<n;i++)
            sum += cost[i];
        return sum-sub;
    }
};