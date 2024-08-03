#include "hash_table.h"

static hash_node_t* create_hash_node(const char* key, int value) {
    hash_node_t* new_node =  (hash_node_t*)malloc(sizeof(hash_node_t));
    // malloc in strdup
    new_node->key = strdup(key);
    new_node->value = value;
    return new_node;
}

static void destroy_hash_node(hash_node_t* node) {
    free(node->key);
    free(node);
}

hash_table_t* create_hash_table(unsigned int (*hash_function)(const char*)) {
    hash_table_t* ht = (hash_table_t*)malloc(sizeof(hash_table_t));
    ht->hash_function = hash_function;
    for (int i = 0; i < TABLE_SIZE; ++i) {
       ht->table[i] = NULL;
    }
    return ht;
}

void destroy_hash_table(hash_table_t* ht) {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        hash_node_t* cur = ht->table[i];
        while (cur != NULL) {
            hash_node_t* tmp = cur;
            cur = cur->next;
            destroy_hash_node(tmp);
        }
    }
    free(ht);
}

void insert_hash_table(hash_table_t* ht, const char* key, int value) {
    unsigned int index = ht->hash_function(key);
    hash_node_t* node = create_hash_node(key, value);
    if (ht->table[index] == NULL) {
        ht->table[index] = node;
    } else {
        hash_node_t* cur = ht->table[index];
        while (cur->next) {
            cur = cur->next;
        }
        cur->next = node;
    }
}

void delete_hash_table(hash_table_t* ht, const char* key) {
    unsigned int index = ht->hash_function(key);
    hash_node_t* node = ht->table[index];
    hash_node_t* pre = (hash_node_t*)malloc(sizeof(hash_node_t));
    pre->next = node;
    while (pre->next) {
        if (strcmp(pre->next->key, key) == 0) {
            hash_node_t* tmp = pre->next;
            pre->next = pre->next->next;
            destroy_hash_node(tmp);
        }
        pre = pre->next;
    }
    free(pre);
}

/*
    search success: return 0
    search fail: return -1
*/
int search_hash_table(hash_table_t* ht, const char* key, int* value) {
    unsigned int index = ht->hash_function(key);
    hash_node_t* node = ht->table[index];
    hash_node_t* cur = node;
    while (cur != NULL) {
        if (strcmp(cur->key, key) == 0) {
            *value = cur->value;
            return 0;
        }
        cur = cur->next;
    }
    return -1;
}