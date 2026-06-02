class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration,
                           vector<int>& waterStartTime, vector<int>& waterDuration) 
    {
        
        int minTime = INT_MAX;
        
        for (int i = 0; i < landStartTime.size(); ++i) 
        {
            for (int j = 0; j < waterStartTime.size(); ++j) 
            {
                int landStart = landStartTime[i];
                int landEnd = landStart + landDuration[i];
                
                int waterStart = max(waterStartTime[j], landEnd);
                int totalTime1 = waterStart + waterDuration[j];
                
                int waterStartAlt = waterStartTime[j];
                int waterEnd = waterStartAlt + waterDuration[j];

                int landStartAlt = max(landStartTime[i], waterEnd);
                int totalTime2 = landStartAlt + landDuration[i];

                minTime = min({minTime, totalTime1, totalTime2});
            }
        }
        
        return minTime;
    }
};
