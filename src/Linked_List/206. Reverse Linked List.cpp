/**
 * 链表逆序
 * 过程很简单
 * 每次拿到一个节点，就让该节点指向前一个节点
 * 此时，需要有一个指针pre保存前一个节点
 * 然后，我们要移动到下一个节点，但是此时我们node->next指向了前一个节点
 * 所以在让该节点指向前一个节点之前，我们需要先用next指针保存后一个节点
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* next = nullptr;
        while(head){
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
};