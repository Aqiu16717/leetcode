#include <iostream>
#include <unordered_map>
#include <cassert>
#include <memory>

using namespace std;

struct TrieNode {
    // The default initialization is false, which is more convenient
    // for subsequent operations
    TrieNode() : isEnd(false) {
    }
    bool isEnd;
    unordered_map<char, unique_ptr<TrieNode>> children;
};

class Trie {
public:
    Trie() : root(make_unique<TrieNode>()) {
    }
    ~Trie() {
    }

    void insert(string word) {
        TrieNode* node = root.get();
        for (char c : word) {
            if (node->children.count(c) == 0) {
                node->children[c] = make_unique<TrieNode>();
            }
            node = node->children[c].get();
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root.get();
        for (char c : word) {
            if (node->children.count(c) == 0) {
                return false;
            }
            node = node->children[c].get();
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root.get();
        for (char c : prefix) {
            if (node->children.count(c) == 0) {
                return false;
            }
            node = node->children[c].get();
        }
        return true;
    }

private:
    unique_ptr<TrieNode> root;
};

int main() {
    Trie* trie = new Trie();
    trie->insert("apple");
    assert(trie->search("apple") == true);
    assert(trie->search("app") == false);
    assert(trie->startsWith("app") == true);
    trie->insert("app");
    assert(trie->search("app") == true);
    return 0;
}
