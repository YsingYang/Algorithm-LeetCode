class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head)   return true;
        if(!head->next)     return true;
        ListNode *slow=head,*fast=head;
        while(fast&&fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast)  slow=slow->next;
        ListNode *sh=slow,*now=sh->next;
        sh->next=nullptr;
        while(now){
            ListNode *temp = now;
            now=now->next;
            temp->next=sh;
            sh=temp;
        }
        now=sh;
        while(now){
            if(head->val!=now->val)   
                return false;
            head=head->next;
            now=now->next;
        }
        return true;
    }
};
/*
  It doesn't like a good solution,I will improve it next time.
 */
