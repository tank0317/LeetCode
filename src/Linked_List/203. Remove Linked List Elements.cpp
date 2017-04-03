/**
 * 删除链表中所有值为val的节点
 * 首先创建一个preHead头结点
 * 然后通过pre指针操作，每当后一个节点值为val时，则删除该节点
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* preHead = new ListNode(0);
        ListNode* pre = preHead;
        pre->next = head;
        while(pre && pre->next){
            while(pre->next && pre->next->val == val){
                pre->next = pre->next->next;
            }
            pre = pre->next;
        }
        return preHead->next;
    }
};