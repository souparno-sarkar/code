class Solution {
public:
    bool sol(int n , vector<int>& t)
    {
        if(n == 1) return true;
        if(n == 2) return false;
        if(t[n] != -1) return t[n];
        for(int i=1;i<=sqrt(n);i++)
        {
            if(!sol(n-i*i , t))
                return t[n] = true;
        }
        return t[n] = false;
    }
    bool winnerSquareGame(int n) {
        vector<int> t(n+1 , -1);
        return sol(n , t);
    }
};