#include <stdio.h>

typedef struct node_t
{
    int val;
    struct node_t* next;
} node_t;


void merge(node_t* left, node_t* mid, node_t* right) {
}

void merge_sort(node_t* left, node_t* right) {
    node_t* mid;
    merge_sort(left, mid);
    merge_sort(mid->next, right);
    merge(left, mid, right);
}

node_t* sort_list(node_t* head) {
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
