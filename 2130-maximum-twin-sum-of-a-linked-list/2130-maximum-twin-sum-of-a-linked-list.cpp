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
class Solution {
public:
    int pairSum(ListNode* head) 
    {
        ListNode* temp = head;
        vector<int> nums;
        while(temp)
        {
            int num = temp->val;
            nums.push_back(num);
            temp = temp->next;
        }  
        int st = 0;
        int end = nums.size()-1;
        int max_sum = -1e9;
        while(st < end)
        {
            int sum = nums[st] + nums[end];
            max_sum = max(sum , max_sum);
            st++;
            end--;
        }
        return max_sum;
    }
};