#include <stdio.h>
#include <stdlib.h>

typedef struct node_t {
    int val;
    struct node_t* next;
} node_t;

node_t* list_deep_copy(node_t* list) {
    if (list == NULL) {
        return NULL;
    }

    node_t* old_head = list;

    node_t* new_head = (node_t*)malloc(sizeof(node_t));
    new_head->val = old_head->val;

    node_t* new_node = new_head;

    node_t* old_node = old_head->next;
    while (old_node) {
        node_t* node = (node_t*)malloc(sizeof(node_t));
        node->val = old_node->val;
        new_node->next = node;
        new_node = node;
        old_node = old_node->next;
    }
    new_node->next = NULL;

    return new_head;
}

void list_print(node_t* list) {
    while (list) {
        printf("%p:%d\t", list, list->val);
        list = list->next;
    }
    printf("\n");
}

int main()
{
    node_t* head = (node_t*)malloc(sizeof(node_t));
    head->val = 0;
    node_t* node1 = (node_t*)malloc(sizeof(node_t));
    node1->val = 1;
    node_t* node2 = (node_t*)malloc(sizeof(node_t));
    node2->val = 2;
    node_t* node3 = (node_t*)malloc(sizeof(node_t));
    node3->val = 3;
    head->next = node1;
    node1->next = node2;
    node2->next = node3;
    list_print(head);
    node_t* new_head = list_deep_copy(head);
    list_print(new_head);

    return 0;
}

