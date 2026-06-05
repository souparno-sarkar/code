using ll = long long;
class Solution {
public:
    string s;
    int n;

    ll dpTotalNumber[16][10][10];
    ll dpTotalWaveNumber[16][10][10];

    pair<ll,ll> sol(int curr, int prev, int prevPrev, bool isLimitWithActualNumber, 
    bool isLeadingZeros)
    {
        if(curr == n)
            return {1,0};

        if(!isLimitWithActualNumber && !isLeadingZeros && prev >= 0 && prevPrev >= 0)
        {
            if(dpTotalNumber[curr][prev][prevPrev] != -1 && 
            dpTotalWaveNumber[curr][prev][prevPrev] != -1)
                return {dpTotalNumber[curr][prev][prevPrev] , 
                        dpTotalWaveNumber[curr][prev][prevPrev]};
        }
        
        ll totalNumber = 0;
        ll totalWaveScore = 0;

        int limitDigit = isLimitWithActualNumber ? (s[curr]-'0') : 9;

        for(int digit=0; digit<=limitDigit; digit++)
        {
            bool newLeadingZeros = isLeadingZeros && (digit == 0);
            
            int newPrevPrev = prev;
            int newPrev = newLeadingZeros ? -1 : digit;

            auto[remainTotalNumber , remainTotalWaveScore] = sol(curr+1, newPrev, newPrevPrev, isLimitWithActualNumber && (digit == limitDigit), newLeadingZeros);

            if(!newLeadingZeros && prev >= 0 && prevPrev >= 0)
            {
                bool isPeek = (prev > digit) && (prevPrev < prev);
                bool isValley = (prev < digit) && (prevPrev > prev);
                
                if(isPeek || isValley)
                {
                    totalWaveScore += remainTotalNumber;
                }
            }
            totalWaveScore += remainTotalWaveScore;
            totalNumber += remainTotalNumber;

            if(!isLimitWithActualNumber && !isLeadingZeros && prev >= 0 && prevPrev >= 0)
            {
                dpTotalNumber[curr][prev][prevPrev] = totalNumber;
                dpTotalWaveNumber[curr][prev][prevPrev] = totalWaveScore;
            }
        }

        return {totalNumber , totalWaveScore};
    }

    ll func(ll num)
    {
        if(num <= 100)  // need at leadt 3 digit to compare;
            return 0;

        memset(dpTotalNumber, -1, sizeof(dpTotalNumber));
        memset(dpTotalWaveNumber, -1, sizeof(dpTotalWaveNumber));
        
        s = to_string(num);
        n = s.size();

        /*int prev = -1;
        int prevPrev = -1;
        int curr = 0;
        bool isLimitWithActualNumber = true;
        bool isLeadingZeros = true; */

        auto[totalNumber , totalWaveScore] = sol(0,-1,-1,true,true);
        return totalWaveScore;

    }
    long long totalWaviness(long long num1, long long num2) 
    {
        return func(num2) - func(num1-1);
    }
};