class Solution {
public:
    int earliestFinishTime(vector<int>& ls, vector<int>& ld, vector<int>& ws,
     vector<int>& wd) 
    {
        // land first then water;
        int finish1 = 1e9;
        for(int i=0;i<ls.size();i++)
            finish1 = min(finish1 , ls[i]+ld[i]);
        int finish2 = 1e9;
        for(int i=0;i<ws.size();i++)
            finish2 = min(finish2 , max(finish1 , ws[i])+wd[i]);
        int res1 = finish2;

        // water first then land 
        int finish3 = 1e9;
        for(int i=0;i<ws.size();i++)
            finish3 = min(finish3 , ws[i]+wd[i]);
        int finish4 = 1e9;
        for(int i=0;i<ls.size();i++)
            finish4 = min(finish4 , max(finish3 , ls[i])+ld[i]);
        int res2 = finish4;

        return min(res1 , res2);   
    }
};