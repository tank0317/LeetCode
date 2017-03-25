/**
 * 两个有序链表的合并，
 * 通常我们会创建一个头结点，然后操作合并后的链表，如方法一
 * 当然我们也可以用双重指针pointer to pointer来做，如方法二
 * 两种方法的思路是一样的，只不过是怎么操作链表的问题，
 * 相对来说利用头结点的方法更加容易理解
 * 不过如果对指针的理解到位的话，利用双重指针的方法更加直接，也很容易理解
 **/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //方法一
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* preHead = new ListNode(0);
        ListNode* tmp = preHead;
        while(l1 && l2){
            if(l1->val < l2->val){
                tmp->next = l1;
                l1 = l1->next;
            }else{
                tmp->next = l2;
                l2 = l2->next;
            }
            tmp = tmp->next;
        }
        tmp->next = l1 ? l1 : l2;
        return preHead->next;
    }
};

//方法二
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head = nullptr;
        ListNode** tmp = &head;
        while(l1 && l2){
            if(l1->val < l2->val){
                *tmp = l1;
                l1 = l1->next;
            }else{
                *tmp = l2;
                l2 = l2->next;
            }
            tmp = &((*tmp)->next);
        }
        *tmp = l1 ? l1 : l2;
        return head;
    }
};