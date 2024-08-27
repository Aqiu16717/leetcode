#include <stdbool.h>

typedef struct trie_node {
    bool is_end;
    struct trie_node* children[26];
} trie_node_t;

trie_node_t* trie_create() {
}

void trie_free() {
}

void trie_insert(trie_node_t* t, char* world) {
}

bool trie_search(trie_node_t* t, char* world) {
}

bool trie_start_with() {
}

void test() {
}

int main()
{
    test();
    return 0;
}