#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODE_NUM 100

typedef struct tree_node {
    int data;
    struct tree_node* left;
    struct tree_node* right;
} tree_node_t;

tree_node_t* tree_node_create(int val) {
    tree_node_t* node = (tree_node_t*)malloc(sizeof(tree_node_t));
    node->data = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void tree_destroy(tree_node_t* root) {
    if (!root) {
        tree_destroy(root->left);
        tree_destroy(root->right);
        free(root);
    }
}

void tree_inorder_print(tree_node_t* root) {
    if (root == NULL) {
        return;
    }
    tree_inorder_print(root->left);
    printf("%d\t", root->data);
    tree_inorder_print(root->right);
}

#if 0
void tree_level_print(tree_node_t* root) {
    tree_node_t* que[MAX_NODE_NUM];
    int front = 0;
    int rear = 0;
    que[rear] = root;
    rear = (rear - 1) % MAX_NODE_NUM;

    while (front != rear) {
        int n = top + 1;
        tree_node_t* node = stk[top--];
        for (int i = 0; i < n; ++i) {
            printf("%d\t", node->data);
            if (node->left) {
                stk[++top] = node->left;
            }
            if (node->right) {
                stk[++top] = node->right;
            }
        }
        printf("\n");
    }
}
#endif

/*
insert(root, 65)

      50
     /  \
   30    70
  /  \  /  \
20  40 60  80
       

      50
     /  \
   30    70
  /  \  /  \
20  40 60  80
        \
        65

*/
tree_node_t* insert_recursive(tree_node_t* root, int val) {
    tree_node_t* node = (tree_node_t*)malloc(sizeof(tree_node_t));
    memset(node, 0, sizeof(tree_node_t));
    node->data = val;
    if (!root) {
        return node;
    }
    if (val < root->data) {
        root->left = insert_recursive(root->left, val);
    } else {
        root->right = insert_recursive(root->right, val);
    }
    return root;
}

tree_node_t* insert_iterative(tree_node_t* root, int val) {
    tree_node_t* node = (tree_node_t*)malloc(sizeof(tree_node_t));
    memset(node, 0, sizeof(tree_node_t));
    node->data = val;
    if (!root) {
        return node;
    }

    tree_node_t* parent = root;
    tree_node_t* current = root;

    while (current) {
        parent = current;
        if (current->data > val) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (parent->data > val) {
        parent->left = node;     
    } else {
        parent->right = node;
    }

    return root;
}


tree_node_t* search_recursive(tree_node_t* root, int val) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == val) {
        return root;
    } else if (root->data > val) {
        return search_recursive(root->left, val);
    } else {
        return search_recursive(root->right, val);
    }
}

tree_node_t* search_iterative(tree_node_t* root, int val) {
    while (root && root->data != val) {
        if (root->data > val) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return root;
}

tree_node_t* maximum(tree_node_t* root) {
    if (!root) {
        return NULL;
    }
    tree_node_t* cur = root;
    while (cur->right) {
        cur = cur->right;
    }
    return cur;
}

tree_node_t* minimum(tree_node_t* root) {
    if (!root) {
        return NULL;
    }
    tree_node_t* cur = root;
    while (cur->left) {
        cur = cur->left;
    }
    return cur;
}

tree_node_t* predecessor(tree_node_t* root, tree_node_t* node) {
    if (!root || !node) {
        return NULL;
    }

    if (node->left) {
        return maximum(node->left);
    }

    tree_node_t* pre = NULL;
    tree_node_t* cur = root;
    while (cur != node) {
        if (cur->data > node->data) {
            cur = cur->left;
        } else {
            pre = cur;
            cur = cur->right;
        }
    }
    return pre;
}

tree_node_t* successor(tree_node_t* root, tree_node_t* node) {
    if (!root || !node) {
        return NULL;
    }
    if (node->right) {
        return minimum(node->right);
    }
    tree_node_t* suc = NULL;
    tree_node_t* cur = root;
    while (cur != node) {
        if (cur->data > node->data) {
            suc = cur;
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    return suc;
}

tree_node_t* delete(tree_node_t* root,int val) {
    if (!root) {
        return NULL;
    }

    if (root->data > val) {
        root->left = delete(root->left, val);
    } else if (root->data < val) {
        root->right = delete(root->right, val);
    } else {
        // no children
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        }
        // two children
        if (root->left && root->right) {
            // don't use successor(), because root have left and right child,
            // successor() will do repeated work.
            tree_node_t* tmp = minimum(root->right);
            root->data = tmp->data;
            // delete node with no children
            root->right = delete(root->right, tmp->data);
            return root;
        }
        // one child
        if (root->left) {
            tree_node_t* tmp = root;
            root = root->left;
            free(tmp);
            return root;
        }
        if (root->right) {
            tree_node_t* tmp = root;
            root = root->right;
            free(tmp);
            return root;
        }
    }

    return root;
}


/*
    20
   /  \
  10   30
      /  \
     25   40

*/
void test() {
    tree_node_t* root = NULL;
    root = insert_iterative(root, 5);
    root = insert_iterative(root, 3);
    root = insert_iterative(root, 7);
    root = insert_iterative(root, 2);
    root = insert_iterative(root, 4);
    root = insert_iterative(root, 6);
    root = insert_iterative(root, 8);

    // tree_level_print(root);
    printf(">> inorder print\n");
    tree_inorder_print(root);
    printf("\n");

    tree_node_t* node = NULL;

    printf(">> maxmum\n");
    node = maximum(root);
    printf("max:%d\n", node->data);

    printf(">> minum\n");
    node = minimum(root);
    printf("min:%d\n", node->data);


    printf(">> find node 4\n");
    node = search_iterative(root, 4);
    if (!node) {
        printf("not exist\n");
    }
    printf("exist:%d\n", node->data);

    printf(">> node 4 predecessor\n");
    tree_node_t* pre = predecessor(root, node);
    printf("%d\n", pre->data);

    printf(">> node 4 successor\n");
    tree_node_t* suc = successor(root, node);
    printf("%d\n", suc->data);

    printf(">> find node 2\n");
    node = search_recursive(root, 2);
    if (!node) {
        printf("not exist\n");
    }
    printf("exist:%d\n", node->data);

    printf(">> delete 8 and inorder print\n");
    root = delete(root, 8);
    tree_inorder_print(root);
    printf("\n");

    printf(">> delete 5 and inorder print\n");
    root = delete(root, 5);
    tree_inorder_print(root);
    printf("\n");

    tree_destroy(root);
}

int main()
{
    test();
    return 0;
}