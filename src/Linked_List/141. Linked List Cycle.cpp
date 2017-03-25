/**
 * 利用Floyd判圈法
 * 首先设定两个指针slow和fast分别指向链表头
 * 然后slow每次前进一步，fast每次前进两步
 * 如果之后的过程中，fast遇到链表尾部则不存在环
 * 如果之后slow和fast再次相遇，那么肯定存在环。
 * 或者说如果存在环，那么slow和fast肯定会相遇。
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
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return true;
        }
        return false;
    }
};