#include <iostream>
#include <cstdio>

void recur(int* arr, int len, int index) {
    if (index == len) {
        return;
    }
    recur(arr, len, index + 1);
    printf("%d\n", arr[index]);
}

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val) {
    }
};

void recur_list(ListNode* head) {
    if (head == nullptr) {
        return;
    }
    recur_list(head->next);
    printf("%d\n", head->val);
}

int main() {

    // array
#if 0
    int arr[10];
    for (int i = 0; i < 10; ++i) {
        arr[i] = i + 1;
    }
    recur(arr,10,0);
#endif

    // list
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    recur_list(node1);

    printf("end\n");

    return 0;
}