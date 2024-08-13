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

// v1
node_t* sort_list(node_t* head) {
    merge_sort(head, NULL);
}

// v2
node_t* sort_list_botom_up(node_t* head) {
    // the list is empty or has only one node
    if (head == NULL || head->next == NULL) {
        return head;
    }
    // len: the length of the list
    int len = 0;
    for (node_t* p = head; p != NULL; p = p->next) {
        ++len;
    }
    node_t dummy_head;
    dummy_head.next = head;
    // sublen: the length of sub list
    // sublen starts from 1 and doubles each time
    for (int sublen = 1; sublen < len; sublen <<= 1) {
        // pre: the tail of last time sorted sub list
        node_t* pre = &dummy_head;
        // cur: iterate the list
        node_t* cur = dummy_head.next;
        while (cur) {
            // the first list to merge
            node_t* head1 = cur;
            for (int i = 1; i < sublen && cur->next; ++i) {
                cur = cur->next;
            }
            // when loop is over: i == sublen or cur->next == NULL
            // cut the list
            node_t* nxt = cur->next;
            cur->next = NULL;
            cur = nxt;
            // the second list to merge
            node_t* head2 = cur;
            for (int i = 1; i < sublen && cur && cur->next; ++i) {
                cur = cur->next;
            }
            // when loop is over: i == sublen or cur == NULL or cur->next == NULL
            if (cur) {
                nxt = cur->next;
                cur->next = NULL;
                cur = nxt;
            }
            pre->next = merge(head1, head2);
            while (pre->next) {
                pre = pre->next;
            }
        }
    }
    return dummy_head.next;
}

void test_sort_list() {
    printf("%s\n", __func__);
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

}

void test_sort_list_botom_up() {
    printf("%s\n", __func__);
    node_t* head = create_node(4);
    node_t* n2 = create_node(2);
    node_t* n3 = create_node(1);
    node_t* n4 = create_node(3);
    head->next = n2;
    n2->next = n3;
    n3->next = n4;

    print_list(head);
    node_t* new_head = sort_list_botom_up(head);
    print_list(new_head);
}


int main()
{
    test_sort_list();
    test_sort_list_botom_up();
    return 0;
}
