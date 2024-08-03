#include "hash_table.h"


unsigned int xor_hash(hash_table_t* ht,const char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash &= *key;
        ++key;
    }
    return hash % ht->capacity;
}

void test_normal() {
    hash_table_t* htb = create_hash_table(TABLE_INITIAL_SIZE, xor_hash);
    insert_hash_table(htb, "Tom", 123);
    int value;
    search_hash_table(htb, "Tom", &value);
    printf("values:%d\n", value);
    printf("size:%u\n",htb->size);
    insert_hash_table(htb, "Tom", 456);
    search_hash_table(htb, "Tom", &value);
    printf("update:");
    printf("values:%d\n", value);
    printf("size:%u\n",htb->size);
    destroy_hash_table(htb);
}

void test_resize() {
    hash_table_t* htb = create_hash_table(TABLE_INITIAL_SIZE, xor_hash);
    insert_hash_table(htb, "Tom", 123);
    printf("size:%u\n",htb->size);
    printf("capacity:%u\n",htb->capacity);

    insert_hash_table(htb, "Tom1", 123);
    printf("size:%u\n",htb->size);
    printf("capacity:%u\n",htb->capacity);

    insert_hash_table(htb, "Tom2", 123);
    printf("size:%u\n",htb->size);
    printf("capacity:%u\n",htb->capacity);

    insert_hash_table(htb, "Tom3", 123);
    printf("size:%u\n",htb->size);
    printf("capacity:%u\n",htb->capacity);

    insert_hash_table(htb, "Tom4", 123);
    printf("size:%u\n",htb->size);
    printf("capacity:%u\n",htb->capacity);

    insert_hash_table(htb, "Tom5", 123);
    printf("size:%u\n",htb->size);
    printf("capacity:%u\n",htb->capacity);

    insert_hash_table(htb, "Tom6", 123);
    printf("size:%u\n",htb->size);
    printf("capacity:%u\n",htb->capacity);

    insert_hash_table(htb, "Tom7", 123);
    printf("size:%u\n",htb->size);
    printf("capacity:%u\n",htb->capacity);

    insert_hash_table(htb, "Tom8", 123);
    printf("size:%u\n",htb->size);
    printf("capacity:%u\n",htb->capacity);

    insert_hash_table(htb, "Tom9", 123);
    printf("size:%u\n",htb->size);
    printf("capacity:%u\n",htb->capacity);

    destroy_hash_table(htb);
}

int main()
{
    test_normal();
    test_resize();
    return 0;
}
