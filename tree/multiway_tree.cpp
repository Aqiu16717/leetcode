#include <iostream>
#include <functional>
#include <vector>
#include <stack>

template <typename T>
class Node {
public:
    T value;
    std::vector<Node> children; // 下标从小到大表示叶子节点顺序从左到右
};

template <typename T>
void recursive_preorder_traverse(const Node<T> &root, const std::function<void(const T&)> &traverser) {
    traverser(root.value);
    for (const auto& child : root.children) {
        recursive_preorder_traverse(child, traverser);
    }
}

template <typename T>
void nonrecursive_preorder_traverse(const Node<T> &root, const std::function<void(const T&)> &traverser) {
    // TODO
    Node<T> p = root;
    //Node<T> prev;
    std::stack<Node<T>> st;
    //st.push(p);
    traverser(p);
    
    #if 0
    while (!st.empty()) {
        while (!p.children.empty()) {
            p = p.children[0];
        }
        
        //Node<T> node = st.top();
        //st.pop();
    }
    #endif
}

int main(void) {
    Node<int> tree {
        11, 
        {
            {
                21, 
                {
                    {31}
                }
            }, 
            {
                22
            }, 
            {
                23
            }
        }
    };
    nonrecursive_preorder_traverse<int>(tree, [](const int& value) -> void { std::cout << value << " "; });
    recursive_preorder_traverse<int>(tree, [](const int& value) -> void { std::cout << value << " "; });
    return 0;
}