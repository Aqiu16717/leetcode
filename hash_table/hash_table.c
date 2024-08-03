#include "hash_table.h"

#define LOAD_FACTOR_THRESHOLD 0.75

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

static void resize_hash_table(hash_table_t* ht) {
    uint32_t new_capacity = ht->capacity * 2;
    hash_node_t** new_table = (hash_node_t**)calloc(new_capacity, sizeof(hash_node_t));
    for (int i = 0; i < ht->capacity; ++i) {
        hash_node_t* node = ht->table[i];
        while (node != NULL) {
            uint32_t new_index = ht->hash_function(ht, node->key);
            hash_node_t* nxt = node->next;
            node->next = ht->table[new_index];
            ht->table[new_index] = node;
            node = nxt;
        }
    }
    free(ht->table);
    ht->table = new_table;
    ht->capacity = new_capacity;
}

hash_table_t* create_hash_table(int capacity, unsigned int (*hash_function)(hash_table_t*, const char*)) {
    hash_table_t* ht = (hash_table_t*)malloc(sizeof(hash_table_t));
    ht->table = (hash_node_t**)calloc(capacity, sizeof(hash_node_t*));
    ht->size = 0;
    ht->capacity = capacity;
    ht->hash_function = hash_function;
    return ht;
}

void destroy_hash_table(hash_table_t* ht) {
    for (int i = 0; i < ht->capacity; ++i) {
        hash_node_t* cur = ht->table[i];
        while (cur != NULL) {
            hash_node_t* tmp = cur;
            cur = cur->next;
            destroy_hash_node(tmp);
        }
    }
    free(ht->table);
    free(ht);
}

void insert_hash_table(hash_table_t* ht, const char* key, int value) {
    if ((double)ht->size / ht->capacity > LOAD_FACTOR_THRESHOLD) {
        printf("debug\n");
        resize_hash_table(ht);
    }

    unsigned int index = ht->hash_function(ht, key);
    hash_node_t* cur_node = ht->table[index];
    // check whether the key already exites
    while (cur_node != NULL) {
        if (strcmp(cur_node->key, key) == 0) {
            cur_node->value = value;
            return;
        }
        cur_node = cur_node->next;
    }

    hash_node_t* node = create_hash_node(key, value);
    node->next = ht->table[index];
    ht->table[index] = node;
    ++ht->size;
}

void delete_hash_table(hash_table_t* ht, const char* key) {
    unsigned int index = ht->hash_function(ht, key);
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
    unsigned int index = ht->hash_function(ht, key);
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