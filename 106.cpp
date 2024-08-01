class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (postorder.empty()) { // 空节点
            return nullptr;
        }
        int left_size = ranges::find(inorder, postorder.back()) - inorder.begin(); // 左子树的大小
        vector<int> in1(inorder.begin(), inorder.begin() + left_size);
        vector<int> in2(inorder.begin() + left_size + 1, inorder.end());
        vector<int> post1(postorder.begin(), postorder.begin() + left_size);
        vector<int> post2(postorder.begin() + left_size, postorder.end() - 1);
        TreeNode *left = buildTree(in1, post1);
        TreeNode *right = buildTree(in2, post2);
        return new TreeNode(postorder.back(), left, right);
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        post_idx = postorder.size() - 1;
        for (int i = 0; i < inorder.size(); ++i) {
            idx_map[inorder[i]] = i;
        }
        return helper(0, inorder.size() - 1, inorder, postorder);
    }
 
private:
    TreeNode* helper(int in_left, int in_right, vector<int>& inorder, vector<int>& postorder) {
        if (in_left > in_right) {
            return nullptr;
        }

        int root_val = postorder[post_idx];
        TreeNode* root = new TreeNode(root_val);

        int index = idx_map[root_val]; 
        --post_idx;
        root->right = helper(index + 1, in_right, inorder, postorder);
        root->left = helper(in_left, index - 1, inorder, postorder);

        return root;
    } 

private:
    int post_idx;
    unordered_map<int, int> idx_map;
};