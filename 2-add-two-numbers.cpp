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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int addtn;
        int carry = 0;
        ListNode *head = NULL;
        ListNode **sum = &head;
        while(l1!=nullptr && l2!=nullptr) {
            addtn = l1->val + l2->val + carry;
            if(addtn>=10) {
                carry = 1;
                *sum=new ListNode(addtn%10);
            }
            else {
                *sum=new ListNode(addtn);
                carry=0;
            }
            l1 = l1->next;
            l2 = l2->next;
            sum=&((*sum)->next);
        }
        while(l1!=nullptr) {
            addtn=l1->val+carry;
            if(addtn>=10) {
                carry = 1;
                *sum=new ListNode(addtn%10);
            }
            else {
                *sum=new ListNode(addtn);
                carry=0;
            }
            l1=l1->next;
            sum=&((*sum)->next);
        }
        while(l2!=nullptr) {
            addtn=l2->val+carry;
            if(addtn>=10) {
                carry = 1;
                *sum=new ListNode(addtn%10);
            }
            else {
                *sum=new ListNode(addtn);
                carry=0;
            }
            l2=l2->next;
            sum=&((*sum)->next);
        }
        while(carry!=0) {
            *sum=new ListNode(carry);
            carry=0;
            sum=&((*sum)->next);
        }
        return head;
    }
};
