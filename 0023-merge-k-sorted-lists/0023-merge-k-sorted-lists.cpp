/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:

    ListNode* mergetwolinklist(ListNode* l1 , ListNode* l2)
    {
        // base case;
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        if(l1->val <= l2->val)
        {
            l1->next = mergetwolinklist(l1->next , l2);
            return l1;
        }
        else
        {
            l2->next = mergetwolinklist(l1 , l2->next);
            return l2;
        }
        return NULL;
    }

    ListNode* devidelinklist(int st , int ed , vector<ListNode*>& lists)
    {
        // base case
        if(st > ed)
            return NULL;
        if(st == ed)
            return lists[st];
        
        int mid = st + (ed-st)/2;
        ListNode* l1 = devidelinklist(st , mid , lists);
        ListNode* l2 = devidelinklist(mid+1 , ed , lists);
        return mergetwolinklist(l1 , l2);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        int n = lists.size();
        return devidelinklist(0 , n-1 , lists);
    }
};