/** 
 * 求两个链表的相交节点，如果不相交， 返回NULL
 * 大致思路是，令p1、p2分别指向两个链表头，每次判断两个节点是否相等，如果不相等则判断下一个节点
 * 此时如果遇到链表尾，则继续从另一个链表头开始，
 * 这样的话两个指针必然会有指向同一个节点的时候，
 * 即使两个链表不相交，那么p1, p2会同时指向链表尾，即同时指向NULL
 */
 
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        if(!p1 || !p2) return nullptr;
        while(p1 != p2){
            p1 = p1 == nullptr ? headB : p1->next;
            p2 = p2 == nullptr ? headA : p2->next;
        }
        return p1;
    }
};