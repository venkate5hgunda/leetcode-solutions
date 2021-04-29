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

// IMPLEMENTATION #1
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


// IMPLEMENTATION #2
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* temp;
        if(lists.size()==0) return temp;
        while(lists.size()>1) {
            temp=mergeTwoLists(lists[0],lists[1]);
            lists.push_back(temp);
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists[0];
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* list;
        if(l1==nullptr) return l2;
        if(l2==nullptr) return l1;
        if(l1->val>l2->val) {
            list=l2;
            list->next=mergeTwoLists(l1,l2->next);
        }
        else {
            list=l1;
            list->next=mergeTwoLists(l1->next,l2);
        }
        return list;
    }
};
