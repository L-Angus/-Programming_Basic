#include <iostream>
#include <vector>
#include <algorithm>

struct ListNode{
    int val;
    ListNode *next;
};

ListNode* removeNthFromEnd(ListNode* head, int n) {
    int size = 0;
    ListNode * tmp= head;
    while (tmp->next){
        tmp = tmp->next;
        size++;
    }
    auto pos = size - n +1;
    if (pos < 1) return nullptr;
    ListNode *curr = head;
    for (size_t i = 0; i < pos - 1; ++i)
    {
        curr = curr->next;
    }
    ListNode* temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return curr;
}
