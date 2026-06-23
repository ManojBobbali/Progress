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
     ListNode* merge(ListNode* a, ListNode* b) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while(a && b) {

            if(a->val < b->val) {
                tail->next = a;
                a = a->next;
            }
            else {
                tail->next = b;
                b = b->next;
            }

            tail = tail->next;
        }

        tail->next = a ? a : b;

        return dummy.next;
    }
    ListNode* solve(vector<ListNode*>& lists,
                    int left,
                    int right)
    {
        if(left == right)
            return lists[left];

        int mid = left + (right-left)/2;

        ListNode* l1 = solve(lists,left,mid);
        ListNode* l2 = solve(lists,mid+1,right);

        return merge(l1,l2);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)return nullptr;
        if(lists.size() == 1)return lists[0];
        return solve(lists,0,lists.size()-1);
    }
};