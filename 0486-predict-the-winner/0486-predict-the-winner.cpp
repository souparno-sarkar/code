using ll = long long;
class Solution {
public:
    ll sum0 = 0;
    ll sum1 = 0;
    bool sol(int ptrLeft , int ptrRight , vector<int>& nums , int cnt)
    {
        if(ptrLeft > ptrRight)
            return sum0 >= sum1;
        else
        {
            if(cnt%2 != 0)
            {
                sum0 += nums[ptrLeft];
                bool left = sol(ptrLeft+1 , ptrRight , nums , cnt+1);
                sum0 -= nums[ptrLeft];

                sum0 += nums[ptrRight];
                bool right = sol(ptrLeft , ptrRight-1 , nums , cnt+1);
                sum0 -= nums[ptrRight];
                return left || right;
            }
            else
            {
                sum1 += nums[ptrLeft];
                bool left = sol(ptrLeft+1 , ptrRight , nums , cnt+1);
                sum1 -= nums[ptrLeft];
                
                sum1 += nums[ptrRight];
                bool right = sol(ptrLeft , ptrRight-1 , nums , cnt+1);
                sum1 -= nums[ptrRight];
                return left && right;
            }
        }
        return sum0 >= sum1;
    }
    bool predictTheWinner(vector<int>& nums) {
        int ptrLeft = 0;
        int ptrRight = nums.size()-1;
        int cnt = 1;
        return sol(ptrLeft , ptrRight , nums , cnt);
    }
};