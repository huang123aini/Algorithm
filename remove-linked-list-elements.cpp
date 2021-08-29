#include <iostream>
/**
 *删除链表中等于给定值 val 的所有节点
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr){}
}

ListNode* removeElements(ListNode* head, int val) {
    //删除头结点
    while (head != nullptr && head->val == val) {
        ListNode* tmp = head;
        head = head->next;
        delete tmp;
    }
    //删除非头结点
    ListNode* cur = head;
    while (cur != nullptr && cur->next != nullptr) {
        if (cur->next->val == val) {
            ListNode* tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
        } else {
            cur = cur->next;
        }
    }
    return head;
    
    
}
int main(int argv, char** argc) {
    
    return 0;
}
