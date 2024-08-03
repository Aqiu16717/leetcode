#include "hash_table.h"


unsigned int xor_hash(const char* key) {
    unsigned int hash = 0;
    while (*key) {
        hash &= *key;
        ++key;
    }
    return hash % TABLE_SIZE;
}

int main()
{
    hash_table_t* htb = create_hash_table(xor_hash);
    insert_hash_table(htb, "Tom", 123);
    int value;
    search_hash_table(htb, "Tom", &value);
    printf("values:%d\n", value);
    destroy_hash_table(htb);

    return 0;
}
