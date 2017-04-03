/**
 * 看着代码有点长，但是过程很简单
 * 首先，找到链表的中点，通过slow, fast两个指针
 * 然后，对链表的后半段进行逆序
 * 最后，对比链表前半段和逆序后的链表后半段，如果完全一样则返回true, 否则false
 **/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        if(!head || !(head->next)) return true;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow != nullptr){
            if(head->val == slow->val){
                head = head->next;
                slow = slow->next;
            }else{
                return false;
            }
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head){
        ListNode *pre = nullptr;
        ListNode *next = nullptr;
        while(head){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};
