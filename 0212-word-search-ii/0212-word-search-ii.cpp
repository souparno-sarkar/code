class Solution 
{
public:
    vector<vector<int>> direction = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<string> res;
    int m , n;
    struct TrieNode
    {
        bool endOfWord;
        string word;
        TrieNode* child[26];
    };

    TrieNode* getNode()
    {
        TrieNode* newNode = new TrieNode();
        newNode->endOfWord = false;
        newNode->word = "";
        for(int i=0;i<26;i++)
            newNode->child[i] = NULL;
        return newNode;
    }

    void insert(TrieNode* root , string& word)
    {
        TrieNode* crawler = root;
        for(int i=0;i<word.size();i++)
        {
            char ch = word[i];
            if(crawler->child[ch-'a'] == NULL)
                crawler->child[ch-'a'] = getNode();
            crawler = crawler->child[ch-'a'];
        }
        crawler->endOfWord = true;
        crawler->word = word;
    }

    void find_word(vector<vector<char>>& board , int i , int j , TrieNode* node)
    {
        if(i >= m || i < 0 || j >= n || j < 0) 
            return;
        char ch = board[i][j];
        if(board[i][j] == '$' || node->child[ch-'a'] == NULL)
            return;

        node = node->child[ch-'a'];

        if(node->endOfWord == true)
        {
            res.push_back(node->word);
            node->endOfWord = false;   // very imp line in exploring forward in tries DS;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for(auto& dir : direction)
        {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            find_word(board , new_i , new_j , node);
        }
        board[i][j] = temp;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        m = board.size();
        n = board[0].size();
        
        TrieNode* root = getNode();
        for(string& word : words)
            insert(root , word);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                char ch = board[i][j];
                if(root->child[ch-'a'] != NULL)
                {
                    find_word(board , i , j , root);
                }
            }
        }
        return res;
    }
};