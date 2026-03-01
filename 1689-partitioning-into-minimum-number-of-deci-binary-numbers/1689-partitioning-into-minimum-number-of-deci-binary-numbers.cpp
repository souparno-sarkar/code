class Solution 
{
public:
    int minPartitions(string n) 
    {
        int max_num = INT_MIN;
        for(int i=0;i<n.size();i++)
        {
            if(isdigit(n[i]))
            {
                int a =n[i]-'0';
                max_num = max(a , max_num);
            }
        }    
        return max_num;
    }
};