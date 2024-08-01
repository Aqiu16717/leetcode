#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>

using namespace std;

struct TreeNode {
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) {}
    int val;
    TreeNode* left;
    TreeNode* right;
};

class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        unordered_map<int, int> index;
        for (int i = 0; i < n; i++) {
            index[inorder[i]] = i;
        }

        function<TreeNode*(int, int, int, int)> dfs = [&](int pre_l, int pre_r, int in_l, int in_r) -> TreeNode* {
            printf("pre_l:%d,pre_r:%d,in_l:%d,in_r:%d\n", pre_l, pre_r, in_l, in_r);
            if (pre_l == pre_r) { // 空节点
                return nullptr;
            }
            int left_size = index[preorder[pre_l]] - in_l; // 左子树的大小
            TreeNode *left = dfs(pre_l + 1, pre_l + 1 + left_size, in_l, in_l + left_size);
            TreeNode *right = dfs(pre_l + 1 + left_size, pre_r, in_l + 1 + left_size, in_r);
            return new TreeNode(preorder[pre_l], left, right);
        };
        return dfs(0, n, 0, n); // 左闭右开区间
    }
};

bool eq_tree(TreeNode* root1, TreeNode* root2) {
    if (root1 == nullptr && root2 == nullptr) {
        return true;
    }
    if (!root1 || !root2) {
        return false;
    }
    return root1->val == root2->val; 
    return eq_tree(root1->left, root2->left) && eq_tree(root1->right, root2->right);
}

int main()
{
    TreeNode* root = new TreeNode(3);
    TreeNode* node1 = new TreeNode(9);
    TreeNode* node2 = new TreeNode(20);
    TreeNode* node3 = new TreeNode(15);
    TreeNode* node4 = new TreeNode(7);

    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;
    
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* tree = s.buildTree(preorder, inorder);

    bool ret = eq_tree(root, tree);
    cout << ret << endl;

    delete root;
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
