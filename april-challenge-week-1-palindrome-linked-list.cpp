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
    bool isPalindrome(ListNode* head) {
        vector<int> val;
        while(head!=nullptr) {
            val.push_back(head->val);
            head = head->next;
        }
        int valSize = val.size();
        for(int i=0;i<valSize/2;i++) {
            if(val[i]!=val[valSize-1-i]) {
                return false;
            }
        }
        return true;
    }
};
