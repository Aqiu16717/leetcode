#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct hash_node_t {
    char* key;
    int value;
    struct hash_node_t* next;
} hash_node_t;

typedef struct
{
    hash_node_t* table[TABLE_SIZE];
    unsigned int (*hash_function)(const char*);
} hash_table_t;

hash_table_t* create_hash_table(unsigned int (*hash_function)(const char*));

void destroy_hash_table(hash_table_t* ht);

void insert_hash_table(hash_table_t* ht, const char* key, int value);

void delete_hash_table(hash_table_t* ht, const char* key);

/*
    search success: return 0
    search fail: return -1
*/
int search_hash_table(hash_table_t* ht, const char* key, int* value);
