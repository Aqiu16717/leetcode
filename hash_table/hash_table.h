#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define TABLE_INITIAL_SIZE 10

typedef struct hash_node_t {
    char* key;
    int value;
    struct hash_node_t* next;
} hash_node_t;

typedef struct hash_table_t
{
    hash_node_t** table;
    unsigned int (*hash_function)(struct hash_table_t* ht, const char*);
    uint32_t size;
    uint32_t capacity;
} hash_table_t;

hash_table_t* create_hash_table(int capacity, unsigned int (*hash_function)(hash_table_t*, const char*));

void destroy_hash_table(hash_table_t* ht);

void insert_hash_table(hash_table_t* ht, const char* key, int value);

void delete_hash_table(hash_table_t* ht, const char* key);

/*
    search success: return 0
    search fail: return -1
*/
int search_hash_table(hash_table_t* ht, const char* key, int* value);
