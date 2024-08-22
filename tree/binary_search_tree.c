#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree_node {
    int data;
    struct tree_node* left;
    struct tree_node* right;
} tree_node_t;

tree_node_t* bst_create() {
}

void bst_free(tree_node_t* root) {
}

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
    if (!root) {
        tree_node_t* node = (tree_node_t*)malloc(sizeof(tree_node_t));
        memset(node, 0, sizeof(tree_node_t));
        node->data = val;
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
        if (!root->left && !root->right) {
            free(root);
            return NULL;
        }
        if (root->left && root->right) {
            // don't use successor(), because root have left and right child,
            // successor() will do repeated work.
            tree_node_t* tmp = minimum(root->right);
            root->data = tmp->data;
            root->right = delete(root, tmp->data);
            return root;
        }
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
}

int main()
{
    test();
    return 0;
}