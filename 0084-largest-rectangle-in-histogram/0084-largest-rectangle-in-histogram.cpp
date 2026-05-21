class Solution 
{
public:
    int largestRectangleArea(vector<int>& heights) 
    {
           vector<int> v1;  // for Nearest smallest to right
           vector<int> v2;  // for Nearest smallest to left
           stack<pair<int,int>> s1;  // right
           stack<pair<int,int>> s2;  // left
           int n = heights.size();
           int sudo_right = n;  // right most boundary (don't hardcode to 7 because it depent on the size of array) 
           int sudo_left = -1;  // left most boundary is always -1
          // int width[n];
           //int h[n];

           for(int i=n-1;i>=0;i--)
           {
            if(s1.size()==0)
            {
                v1.push_back(sudo_right);
            }
            else if(s1.size()>0 && s1.top().first<heights[i])
            {
                v1.push_back(s1.top().second);
            }
            else if(s1.size()>0 && s1.top().first>=heights[i])
            {
                while(s1.size()>0 && s1.top().first>=heights[i])
                {
                    s1.pop();
                }
                if(s1.size()==0)
                {
                     v1.push_back(sudo_right);
                }
                else
                {
                    v1.push_back(s1.top().second);
                }
            }
            s1.push({heights[i],i});
           }
           reverse(v1.begin(),v1.end());
        

           for(int i=0;i<n;i++)
           {
            if(s2.size()==0)
            {
                v2.push_back(sudo_left);
            }
            else if(s2.size()>0 && s2.top().first<heights[i])
            {
                v2.push_back(s2.top().second);
            }
            else if(s2.size()>0 && s2.top().first>=heights[i])
            {
                while(s2.size()>0 && s2.top().first>=heights[i])
                {
                    s2.pop();
                }
                if(s2.size()==0)
                {
                     v2.push_back(sudo_left);
                }
                else
                {
                    v2.push_back(s2.top().second);
                }
            }
            s2.push({heights[i],i});
           }


           for(int i=0;i<n;i++)
           {
             v1[i] = v1[i] - v2[i] - 1;     
           }

           for(int i=0;i<n;i++)
           {
             heights[i]= heights[i]*v1[i];
           }

           int temp = heights[0];
           for(int i=0;i<n;i++)
           {
            if(temp<heights[i])
            {
                temp = heights[i];
            }
           }
           return temp;
    }
};