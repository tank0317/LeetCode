/**
 * 这里题目给定了要删除的节点的指针
 * 我们没办法像通常的思路，先拿到要删除节点的头结点，然后对头结点进行操作
 * 同时限定了这个节点不会是尾节点
 * 所以解题过程中只能直接对这个节点进行操作
 * 这里，我们先把后一个节点的值传递给现在的节点，然后删除后面的节点
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
    void deleteNode(ListNode* node) {
         node->val = node->next->val;
         node->next = node->next->next;
    }
};