class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> rightMatch(m , -1);

        int j = m-1;
        for(int i=n-1;i>=0 && j>=0;i--)
        {
            if(word1[i] == word2[j])
            {
                rightMatch[j] = i;
                j--;
            }
        }

        j = 0;
        vector<int> res;
        bool notMatch = false;
        for(int i=0;i<n && j<m;i++)
        {
            if(word1[i] == word2[j])
            {
                res.push_back(i);
                j++;
            }
            else if(!notMatch)
            {
                if(j+1 == m || rightMatch[j+1] > i)  //--->> str1 = "abz"  str2 = "abc"
                {
                    res.push_back(i);
                    j++;
                    notMatch = true;
                }
            }
        }
        return res.size() == m ? res : vector<int>{};
    }
};