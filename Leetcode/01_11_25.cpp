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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {

        int m[1000001] = {0};

        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=1;
        }


        while(m[head->val])
        {
            head=head->next;
        }

        ListNode* temp1=head;
        ListNode* temp2=head->next;

        if(temp2==NULL)
        {
            return head;
        }

        while(temp2->next!=NULL)
        {
            if(m[temp2->val])
            {
                temp1->next=temp2->next;
                temp2=temp2->next;
            }
            else
            {

            temp1=temp1->next;
            temp2=temp2->next;
            }
        }

        if(m[temp2->val])
        {
            temp1->next=NULL;
        }


        return head;

        
    }
};
