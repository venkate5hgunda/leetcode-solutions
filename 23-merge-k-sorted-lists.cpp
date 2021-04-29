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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result=new ListNode(INT_MIN);
        ListNode* temp=result;
        while(temp!=nullptr) {
            temp->next=findLeastNode(lists);
            temp=temp->next;
        }
        return result->next;
    }
    ListNode* findLeastNode(vector<ListNode*> &lists) {
        ListNode* minNode = new ListNode(INT_MAX);
        for(auto list:lists) {
            if(list!=nullptr) {
                minNode=list->val<minNode->val?list:minNode;
            }
        }
        if(minNode->val==INT_MAX) return nullptr;
        for(auto &list:lists) {
            if(list!=nullptr && list->val==minNode->val) {
                list=list->next;
                break;
            }
        }
        return minNode;
    }
};
