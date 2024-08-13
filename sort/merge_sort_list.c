/**
 * @file merge_sort_list.c
 * @author aq1u
 * @brief 1.分割链表：使用快慢指针找到链表的中点，将链表分成两个部分。
 *        2.合并有序链表：递归地排序链表的两个部分，然后合并这两个有序链表。
 * @version 0.1
 * @date 2024-08-13
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int val;
    struct node* next;
} node_t;


node_t* merge(node_t* head1, node_t* head2) {
    // alloc dumm_head on stack to prevent memory leak.
    node_t dummy_head;
    node_t* cur = &dummy_head;
    node_t* p1 = head1;
    node_t* p2 = head2;

    while (p1 != NULL && p2 != NULL) {
        if (p1->val < p2->val) {
            cur->next = p1;
            p1 = p1->next;
        } else {
            cur->next = p2;
            p2 = p2->next;
        }
        cur = cur->next;
    }
    if (p1) {
        cur->next = p1;
    } else if (p2) {
        cur->next = p2;
    } else {
        // nothing to do
    }
    return dummy_head.next;
}

// tail is not included
node_t* merge_sort(node_t* head, node_t* tail) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == tail) {
        head->next = NULL;
        return head;

    }
    
    // split the list
    // find mid node of the list
    node_t* slow = head;
    node_t* fast = head;
    // at least two node
    while (fast != tail && fast->next != tail) {
        slow = slow->next;
        fast = fast->next->next;
    }
    node_t* mid = slow;
    node_t* h1 = merge_sort(head, mid);
    node_t* h2 = merge_sort(mid, tail);
    return merge(h1, h2);
}

node_t* sort_list(node_t* head) {
    merge_sort(head, NULL);
}

node_t* create_node(int val) {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = NULL;
    return new_node;
}

void free_list(node_t* head) {
    while(head) {
        node_t* tmp = head;
        free(tmp);
        head = head->next;
    }
}

void print_list(node_t* head) {
    while (head) {
        printf("%p:%d ", head, head->val);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    node_t* head = create_node(4);
    node_t* n2 = create_node(2);
    node_t* n3 = create_node(1);
    node_t* n4 = create_node(3);
    head->next = n2;
    n2->next = n3;
    n3->next = n4;

    print_list(head);
    node_t* new_head = sort_list(head);
    print_list(new_head);

    return 0;
}
